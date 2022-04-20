#include "graphe.h"

////// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////

/**
* Constructeur de Graphe.
* @param	_planetes : le vecteur des plan�tes.
* @param	_limite :	la limite repr�sente la capacit� en carburant du vaisseau utilisant ce graphe.
*/
Graphe::Graphe(vector<Planete>* _planetes, float const _limite) {
	this->planetes = _planetes;
	this->nbElements = (short)_planetes->size();
	this->limite = _limite;
	// Initialiser la Matrice.
	for (short x = 0; x < nbElements; x++) {
		for (short y = 0; y < nbElements;y++) {
			if (x != y) {
				/*this->matrice[x][y].initierNoeud(
					(&(*planetes)[x]),
					(&(*planetes)[y]),limite);*/
				// Initialisation de la structure Arete.
				this->matrice[x][y] = Arete(&planetes->at(x), &planetes->at(y),limite);
				this->matrice[x][y].initialiser(limite);
			}
		}
	}
}

/**
* Destructeur de Graphe.
*/
Graphe::~Graphe() {}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Ajouter/ Mettre � jour l�Arete � l�emplacement _x._y.
* Si le vaisseau permet d�emprunter cette Arete.
* @param	_x : la coordonn�e x dans la matrice.
* @param	_y : la coordonn�e y dans la matrice.
*/
void Graphe::ajouterArete(const short _x, const short _y) {
	if (_x != _y) {
		this->matrice[_x][_y].initialiser(limite);
		this->matrice[_y][_x].initialiser(limite);
	}
}

/**
* Retirer l�Arete � l�emplacement _x._y.
* @param	_x : la coordonn�e x dans la matrice.
* @param	_y : la coordonn�e y dans la matrice.
*/
void Graphe::retirerArete(const short _x, const short _y) {
	if (_x != _y) {
		this->matrice[_x][_y].rendreInaccessible();
		this->matrice[_y][_x].rendreInaccessible();
	}
}

/**
* Obtenir la repr�sentation textuelle de la Matrice.
* @return	un string avec les informations de chaque Ar�te.
*/
string Graphe::toStringMatrice() const {
	string res;
	for (short x = 0; x < nbElements; x++) {
		res += "| ";
		for (short y = 0; y < nbElements; y++) {

			// G�rer cout
			res += "{ cout :";
			float cout = matrice[x][y].cout;
			if (cout == 0.0f) {
				res += '0';
			}
			else if (cout == OUT_OF_BOUND) {
				res += "infini";
			}
			else {
				res += to_string(cout);
			}

			// G�rer distance
			res += ", dist :";
			float dist = matrice[x][y].distance;
			if (dist == 0.0f) {
				res += '0';
			}
			else if (dist == OUT_OF_BOUND) {
				res += "infini";
			}
			else {
				res += to_string(dist);
			}

			res += " } | ";
		}
		res += '\n';
	}
	return res;
}