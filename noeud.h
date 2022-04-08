#pragma once
#include "planete.h"
using namespace std;

template<class T>
class noeud
{
public:
	T _element;			// L'élément du noeud.
	noeud* _suivant;	// Le pointeur vers le noeud suivant.


	/**
	* Constructeur de noeud.
	* @param	_plan	l'élément du noeud;
	* @param	_suiv	le pointeur du noeud suivant.
	*/
	template <class T>
	noeud(const T _ele, noeud<T>* _suiv = nullptr) {
		_element = _ele;
		_suivant = _suiv;
	}

	// Destructeur de noeud.
	~noeud(){}
};

