#include "liste.h"

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur de liste.
*/
template <class T>
liste<T>::liste(){
	tete = courant = queue = new noeud<T>();
}

/**
* Destructeur de liste.
*/
template <class T>
liste<T>::~liste(){
	while (tete != NULL) {
		courant = tete;
		tete = tete->_suivant;
		delete courant;
	}
}

//// AUTRES FONCTIONS /////////////////////////////////////////////////////////////////////////////

/**
* Fonction indiquant la présence, ou non, d’un élément dans la liste.
* @param	_element : l’élément à trouver.
* @returns	true si l’élément existe dans la liste, false sinon.
*/
template <class T>
bool liste<T>::trouver(const T& _element){
	// Parcours de la liste
	for (fixerTete(); estDansListe(); suivant()) {
		T _temp = valeurCourante();
		if (_temp == _element) {
			return true;
		}
	}
	return false; // L’élément recherché ne se trouve pas dans la liste
}

/**
* Supprimer l’élément voulu de la liste, s’il est dans la liste.
* @param	_element : l’élément à chercher et supprimer.
*/
template <class T>
void liste<T>::supprimer(const T& _element){
	if (trouver(_element)) {
		noeud<T>* _tempCourant = courant->suivant;
		courant->suivant = _tempCourant->suivant;
		if (queue == _tempCourant) {
			queue = courant;
		}
		delete _tempCourant;
	}
}

/**
* Ajouter l’élément à la fin de la liste.
* @param	_element : l’élément à ajouter à la liste.
*/
template <class T>
void liste<T>::insererFin(const T& _element) {
	queue = queue->suivant = new noeud<T>(_element);
}

/**
* Repositionner le pointeur courant à la tête de la liste.
*/
template <class T>
void liste<T>::fixerTete() {
	courant = tete;
}

/**
* Vérifier que le pointeur courant se trouve dans la liste.
* @return	true si le pointeur ne se trouve pas en fin de liste, false sinon.
*/
template <class T>
bool liste<T>::estDansListe() {
	return (courant != nullptr) && (courant->suivant != nullptr);
}

/**
* Déplacer le pointeur courant sur le noeud suivant.
*/
template <class T>
void liste<T>::suivant() {
	if (courant != nullptr) {
		courant = courant->suivant;
	}
}

/**
* Obtenir l’élément courant dans la liste.
* @return	un élement de type T.
*/
template <class T>
T liste<T>::valeurCourante() const {
	return courant->_suivant->element;
}

/**
* Obtenir une représentation textuelle des éléments de la liste.
* @return	un string avec la représentation textuelle de chaque élément de la liste.
*/
template <class T>
string liste<T>::toString() {
	string res;
	for (fixerTete(); estDansListe(); suivant()) {
		T _temp = valeurCourante();
		res += _temp.toString() + '\n';
	}
	return res;
}

/**
* Obtenir le nombre d’élément dans la liste.
* @return	un short int du nombre d’élément.
*/
template <class T>
short int liste<T>::longueur() const {
	short int _nb = 0;
	for (fixerTete(); estDansListe(); suivant()) {
		_nb++;
	}
	return _nb;
}