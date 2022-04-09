#pragma once
#include "liste.h"
using namespace std;

template<class T>
class Graphe
{
private:
	bool** matriceAdj;										// Matrice d’adjacence des éléments.
	short int nbElements;									// Nombre d’éléments utilisé dans la matrice.
	
	bool** initMatrice();									// Initialisation d’une matrice vide.
public:
	Liste<T>* elements;										// Liste chaînée des elements.

	Graphe(Liste<T>*);										// Constructeur de Graphe.
	~Graphe();												// Destructeur de Graphe.
	void ajouterArete(const short int, const short int);	// Ajouter une arête à la matrice.
	void retirerArete(const short int, const short int);	// Retirer une arête à la matrice.
	bool estArete(const short int, const short int);		// Vérifier s’il y a une arête.
	string toStringMatrice() const;							// Obtenir une représentation textuelle de la matrice d’adjacence.
	/*
	* Dans le cadre de ce projet, il n’est pas question d’insertion ou suppression d’éléments depuis le graphe,
	* La restructuration du graphe n’est donc pas nécessaire
	*/
	//void ajouterElement(T&);
	//void retirerElement(T&);
	//void hydrateMatrice(bool**);

};

#include "graphe.h"

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur de graphe.
* @param	_liste : la liste chaînée d'éléments que possède la matrice d'adjacence.
*/
template<class T>
Graphe<T>::Graphe(Liste<T>* _liste) {
	elements = _liste;
	matriceAdj = initMatrice();
}

/**
* Destructeur de graphe.
*/
template<class T>
Graphe<T>::~Graphe() {
	for (short int x = 0; x < nbElements; x++) {
		// Supprimer les colonnes de la matrice d'adjacence
		delete[] matriceAdj[x];
	}
	// Supprimer la matrice
	delete[] matriceAdj;
}

/**
* Initialisation de la matrice d’adjacence.
*/
template<class T>
bool** Graphe<T>::initMatrice() {
	bool** _matrice;
	nbElements = elements->longueur();
	// Initialiser la matrice
	_matrice = new bool* [nbElements];

	// Initialiser l'axe x
	for (short int x = 0; x < nbElements; x++) {
		_matrice[x] = new bool[nbElements];

		// Initialiser l'axe y
		for (short int y = 0; y < nbElements; y++) {
			_matrice[x][y] = false;
		}
	}

	return _matrice;
}

//// AUTRES FONCTIONS /////////////////////////////////////////////////////////////////////////////

/**
* Ajouter une arête à la matrice.
* Donc la passer à true.
* @param	_x : Coordonnée x dans la matrice.
* @param	_y : Coordonnée y dans la matrice.
*/
template<class T>
void Graphe<T>::ajouterArete(const short int _x,const  short int _y) {
	// La condition permet de garder la diagonale de la matrice vide
	if(_x != _y){
		matriceAdj[_x][_y] = true;
		matriceAdj[_y][_x] = true;
	}
}

/**
* Retirer une arête à la matrice.
* Donc la passer à false.
* @param	_x : Coordonnée x dans la matrice.
* @param	_y : Coordonnée y dans la matrice.
*/
template<class T>
void Graphe<T>::retirerArete(const short int _x,const short int _y) {
	matriceAdj[_x][_y] = false;
	matriceAdj[_y][_x] = false;
}

/**
* Obtenir une représentation visuelle de la matrice d’adjacence.
* @return	un string représentant un tableau avec les états.
*/
template<class T>
string Graphe<T>::toStringMatrice() const {
	string res;
	for (short int x = 0; x < nbElements; x++) {
		res += "| " ;
		for (short int y = 0; y < nbElements; y++) {
			res += to_string(matriceAdj[x][y]) + " | ";
		}
		res += '\n';
		
	}
	return res;
}

/**
* Savoir s’il y a une arête entre deux noeuds du graphe.
* @return	true s’il y a un lien, false sinon.
*/
template<class T>
bool Graphe<T>::estArete(const short int _x, const short int _y) {
	return matriceAdj[_x][_y];
}

///**
//* Ajouter un élément à la liste des éléments.
//* @param	_ele : un element de type T.
//*/
//template<class T>
//void Graphe<T>::ajouterElement(T& _ele) {
//	elements.insererFin(_ele);
//}
//
///**
//* Supprimer un élément à la liste des éléments.
//* @param	_ele : un element de type T.
//*/
//template<class T>
//void Graphe<T>::retirerElement(T& _ele) {
//	elements.supprimer(_ele);
//}
//
//template<class T>
//void Graphe<T>::hydrateMatrice(bool** _matrice) {
//
//}
