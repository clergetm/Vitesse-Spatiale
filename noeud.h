#pragma once
#include "planete.h"
using namespace std;

template<class T>
class noeud
{
public:
	T element;			// L'élément du noeud.
	noeud* suivant;		// Le pointeur vers le noeud suivant.


	/**
	* Constructeur de noeud.
	* @param	_plan :	l'élément du noeud.
	* @param	_suiv :	le pointeur du noeud suivant.
	*/
	template <class T>
	noeud(const T _ele, noeud<T>* _suiv = nullptr) {
		element = _ele;
		suivant = _suiv;
	}

	/**
	* Destructeur de noeud.
	*/
	~noeud(){}
};

