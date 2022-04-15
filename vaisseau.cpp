#include "vaisseau.h"
#include <iostream>
using namespace std;

// Constrûcteur par défaut

Vaisseau::Vaisseau(string _modele, float _capacite) {
	this->modele = _modele;
	this->capacite = _capacite;
}

//Destructeur par défaut
Vaisseau::~Vaisseau(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du Modèle du Vaisseau.
* @return	string du modèle du vaisseau.
*/
string Vaisseau::getModele() const { return this->modele; }

/**
* Getter de la capacité en carburant du Vaisseau.
* @return	la capcité en carburant.
*/
float Vaisseau::getCapacite() const { return this->capacite; }

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Surcharge de l’opérateur ==.
* @param	_vaisseau : le second vaisseau avec lequel comparer.
* @return	true si les modèles sont les mêmes, false sinon.
*/
bool Vaisseau::operator==(Vaisseau _vaisseau) {
	return this->modele == _vaisseau.modele;
}