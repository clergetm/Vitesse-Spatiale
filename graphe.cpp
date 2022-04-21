#include "graphe.h"

////// CONSTRUCTEURS DESTRUCTEURS /////////////////////////////////////////////////////////////////

/**
* Constructeur de Graphe.
* @param	_planetes : le vecteur des planètes.
* @param	_limite :	la limite représente la capacité en carburant du vaisseau utilisant ce graphe.
*/
Graphe::Graphe(vector<Planete>* _planetes, float const _limite) {
	this->planetes = _planetes;
	this->nbElements = (short)_planetes->size();
	this->limite = _limite;
	this->nettoyerVisite();
	// Initialiser la Matrice.
	for (short x = 0; x < nbElements; x++) {
		for (short y = 0; y < nbElements; y++) {
			if (x != y) {
				// Initialisation de la structure Arete.
				this->matrice[x][y] = Arete(&planetes->at(x), &planetes->at(y), limite);
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

/**
* Getter de l'index d'une Planète
* @param	_nomPlanete : le nom de la Planete à trouver.
* @return	l’index d’une Planete correspondante au nom, sinon -1.
*/
short Graphe::getPlaneteidx(const string _nomPlanete) const {
	short i = 0;
	for (auto ite = planetes->cbegin(); ite != planetes->cend(); ++ite) {
		if (ite->getNomPlanete() == _nomPlanete) {
			return i;
		}
		i++;
	}
	return -1;
}

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Ajouter/ Mettre à jour l’Arete à l’emplacement _x._y.
* Si le vaisseau permet d’emprunter cette Arete.
* @param	_x : la coordonnée x dans la matrice.
* @param	_y : la coordonnée y dans la matrice.
*/
void Graphe::ajouterArete(const short _x, const short _y) {
	if (_x != _y) {
		this->matrice[_x][_y].initialiser(limite);
		this->matrice[_y][_x].initialiser(limite);
	}
}

/**
* Retirer l’Arete à l’emplacement _x._y.
* @param	_x : la coordonnée x dans la matrice.
* @param	_y : la coordonnée y dans la matrice.
*/
void Graphe::retirerArete(const short _x, const short _y) {
	if (_x != _y) {
		this->matrice[_x][_y].rendreInaccessible();
		this->matrice[_y][_x].rendreInaccessible();
	}
}

/**
* Obtenir la représentation textuelle de la Matrice.
* @param	_printCout : afficher le cout de voyage sur l’Arete.
* @param	_printDistance : afficher la distance de parcours l’Arete.
* @return	un string avec les informations de chaque Arête.
*/
string Graphe::toStringMatrice(bool _printCout, bool _printDistance) const {
	string res;
	for (short x = 0; x < nbElements; x++) {
		res += "| ";
		for (short y = 0; y < nbElements; y++) {
			if (_printCout) {
				// Gérer cout
				float cout = matrice[x][y].getCout();
				if (cout == 0.0f) {
					res += '0';
				}
				else if (cout == OUT_OF_BOUND) {
					res += "inf";
				}
				else {
					res += to_string((int)cout);
				}
			}

			if (_printCout && _printDistance) { res += ", "; }

			if (_printDistance) {
				// Gérer distance
				float dist = matrice[x][y].getDistance();
				if (dist == 0.0f) {
					res += '0';
				}
				else if (dist == OUT_OF_BOUND) {
					res += "inf";
				}
				else {
					res += to_string((int)dist);
				}
			}
			res += " | ";
		}
		res += '\n';
	}
	return res;
}

//// PARCOURS ////

/**
* Réinitialise la liste des visites à false.
*/
void Graphe::nettoyerVisite() {
	this->visites.fill(false);
}

/**
* Parcours DFS pour obtenir une route entre deux Planetes.
* @param	_src : le nom de la Planete source, le point de départ.
* @param	_dst : le nom de la Planete destination, l'arrivée.
* @return	res : la Route complète à emprunter.
*/
Route Graphe::DFS(const string _src, const string _dst) {
	Route res;

	// Si les deux planètes demandées existent, on peut effectuer le parcours DFS.
	short _idxsrc = getPlaneteidx(_src);
	short _idxdst = getPlaneteidx(_dst);
	if (_idxsrc != -1 && _idxdst != -1) {
		this->nettoyerVisite();
		short _etape = 0;
		this->aideDFS(_src, _dst, res, _etape);
	}

	// Si le chemin ne parvient pas à la destination voulue.
	if (res.arrivee() == nullptr || res.arrivee()->getNomPlanete() != _dst) {
		return Route();
	}
	return res;
}

/**
* Fonction récursive de parcours DFS du Graphe.
* @param	_src	: La planète source du déplacement.
* @param	_dst	: La planète destination à atteindre.
* @param	_route	: La route couramment planifiée.
* @param	_etape	: L’étape couramment modifiée.
*/
void Graphe::aideDFS(const string _src, const string _dst, Route& _route, short& _etape) {
	// Nous parcourons le graphe si et seulement si la destination n’est pas atteinte.
	//  Si il n’y a pas d‘arrivée 
	//   (seulement au lancement)		// Si les noms ne correspondent pas
	if (_route.arrivee() == nullptr || _route.arrivee()->getNomPlanete() != _dst) {

		// Obtenir l’index de la source et de la destination.
		short _idxsrc = this->getPlaneteidx(_src);
		short _idxdst = this->getPlaneteidx(_dst);

		// Marquer visitée cette planète source.
		this->visites[_idxsrc] = true;

		// On parcourt les autres planètes depuis la planète source.
		for (short _y = 0; _y < nbElements; _y++) {
			
			// On vérifie que l’autre planète est accessible et n’a pas été visité.
			if (matrice[_idxsrc][_y].getDistance() <= limite && !visites[_y]) {
			
				if (_route.arrivee() == nullptr || _route.arrivee()->getNomPlanete() != _dst) {
					_route.modifierEtape(_etape, matrice[_idxsrc][_y]);
					// On passe à la prochaine étape.
					_etape++;
				}
				aideDFS(matrice[_idxsrc][_y].dst->getNomPlanete(), _dst, _route, _etape);

			}

		}
		// On repasse sur cette étape.
		_etape--;

	}
}