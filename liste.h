#pragma once
#include <string>
using namespace std;

/**
* Implémentation de la liste sous forme de tableau.
* 
* Dans le cadre de ce projet, le nombre d’éléments tels que les planètes, les vaisseaux reste inchangé dès l’initialisation de la liste.
* Le projet ne nécessite pas l’ajout ou la suppression d’éléments.
*/
template <class T>
class Liste
{
private:
	short int courant;			// Index courant.
	short int nbElement;		// Nombre d’élément dans la liste.
	short int tailleMax;		// Taille maximale de la liste.
	T* elements;				// Tableau d’éléments.
public:
	Liste(const short int);		// Constructeur de la liste.
	~Liste();					// Destructeur de la liste.
	bool trouver(const T&);		// Trouver un élément dans la liste.
	void supprimer(const T&);	// Supprimer un élément dans la liste.
	void insererFin(const T&);	// Insérer un élément à la liste.
	void fixerTete();			// Fixer le noeud courant à la tête de la liste.
	bool estDansListe();		// Vérifier que le noeud courant est dans la liste.
	void suivant();				// Incrémenter de 1 le compteur courant.
	T valeurCourante() const;	// Obtenir la valeur courante.
	string toString() const;	// Obtenir une représentation textuelle des éléments de la liste.
	short int longueur() const;	// Obtenir le nombre d’élément dans la liste.
};

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur de liste.
* @param	_taille : taille maximale du tableau d’éléments.
*/
template<class T>
Liste<T>::Liste(const short int _taille) {
	this->tailleMax = _taille;
	nbElement = 0;
	courant = 0;
	elements = new T[_taille];
}

/**
* Destructeur de liste.
*/
template<class T>
Liste<T>::~Liste() {
	delete[] elements;
}

//// AUTRES FONCTIONS /////////////////////////////////////////////////////////////////////////////

/**
* Fonction indiquant la présence, ou non, d’un élément dans la liste.
* @param	_element : l’élément à trouver.
* @returns	true si l’élément existe dans la liste, false sinon.
*/
template<class T>
bool Liste<T>::trouver(const T& _element) {
	for (fixerTete(); estDansListe(); suivant()) {
		if (valeurCourante() == _element) {
			return true;
		}
	}

	return false;
}

/**
* Supprimer l’élément voulu de la liste, s’il est dans la liste.
* @param	_element : l’élément à chercher et supprimer.
*/
template<class T>
void Liste<T>::supprimer(const T& _element) {
	// Si l’élément est dans le tableau
	if (trouver(_element)) {
		// On décale tous les éléments depuis son emplacement
		for (short int i = courant; i < nbElement - 1; i++) {
			elements[i] = elements[i + 1];
		}
		nbElement--;
	}
}

/**
* Ajouter l’élément à la fin de la liste.
* @param	_element : l’élément à ajouter à la liste.
*/
template<class T>
void Liste<T>::insererFin(const T& _element) {
	elements[nbElement] = _element;
	nbElement++;
}

/**
* Repositionner le pointeur courant à la tête de la liste.
*/
template <class T>
void Liste<T>::fixerTete() {
	courant = 0;
}

/**
* Vérifier que le pointeur courant se trouve dans la liste.
* @return	true si le pointeur ne se trouve pas en fin de liste, false sinon.
*/
template <class T>
bool Liste<T>::estDansListe() {
	return (courant >= 0) && (courant < nbElement);
}

/**
* Incrémenter le compteur courant.
*/
template <class T>
void Liste<T>::suivant() {
	courant++;
}

/**
* Obtenir l’élément courant dans la liste.
* @return	un élement de type T.
*/
template <class T>
T Liste<T>::valeurCourante() const {
	return elements[courant];
}

/**
* Obtenir une représentation textuelle des éléments de la liste.
* @return	un string avec la représentation textuelle de chaque élément de la liste.
*/
template <class T>
string Liste<T>::toString() const {
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
short int Liste<T>::longueur() const {
	return nbElement;
}
