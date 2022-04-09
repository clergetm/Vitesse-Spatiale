#pragma once
#include "noeud.h"
#include <string>
using namespace std;

template <class T>
class liste
{
	noeud<T>* tete;				// Pointeur de la tête de la liste.
	noeud<T>* courant;			// Pointeur de l'élément courant de la liste.
	noeud<T>* queue;			// Pointeur de la queue de la liste.


	liste();					// Constructeur de la liste.
	~liste();					// Destructeur de la liste.
	bool trouver(const T&);		// Trouver un élément dans la liste.
	void supprimer(const T&);	// Supprimer un élément dans la liste.
	void insererFin(const T&);	// Insérer un élément à la liste.
	void fixerTete();			// Fixer le noeud courant à la tête de la liste.
	bool estDansListe();		// Vérifier que le noeud courant est dans la liste.
	void suivant();				// Déplacer le pointeur courant sur le noeud suivant.
	T valeurCourante() const;	// Obtenir la valeur courante.
	string toString();			// Obtenir une représentation textuelle des éléments de la liste.
	short int longueur() const;	// Obtenir le nombre d’élément dans la liste.
};

