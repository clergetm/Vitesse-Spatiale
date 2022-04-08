#pragma once
#include "noeud.h"
#include <string>
using namespace std;

template <class T>
class liste
{
	noeud<T>* tete;				// Pointeur de la tête de la liste.
	noeud<T>* queue;			// Pointeur de la queue de la liste.
	noeud<T>* courant;			// Pointeur de l'élément courant de la liste.

	liste();					// Constructeur de la liste.
	~liste();					// Destructeur de la liste.
	bool trouver(const T&);		// Trouver un élément dans la liste.
	void supprimer(T&);			// Supprimer un élément dans la liste.
	void insererFin(T&);		// Insérer un élément à la liste.
	void fixerTete();			// Fixer le noeud courant à la tête de la liste.
	bool estDansListe();		// Vérifier que le noeud courant est dans la liste.
	noeud<T>* suivant();		// "Incrémenter" le noeud courant.
	string toString();			// Obtenir une représentation textuelle des éléments de la liste.
};

