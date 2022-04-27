#include "vaisseau.h"
using namespace std;

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
* @param	_modele : le nom du vaisseau.
* @param	_capacite : la capacité en carburant du vaisseau.
*/
Vaisseau::Vaisseau(string _modele, float _capacite, vector<Planete>* _planetes = nullptr): modele(_modele), capacite(_capacite), systeme(_planetes,this->capacite) {}

/**
* Destructeur par défaut
*/
Vaisseau::~Vaisseau(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du Modèle du Vaisseau.
* @return	string du modèle du vaisseau.
*/
string Vaisseau::getModele() const { return this->modele; }

/**
* Getter de la capacité en carburant du Vaisseau.
* @return	la capacité en carburant.
*/
float Vaisseau::getCapacite() const { return this->capacite; }

/**
* Getter du système que le Vaisseau peut emprunter.
* @return	un graphe des planètes.
*/
Graphe& Vaisseau::getSysteme() { return this->systeme; }

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Obtenir une représentation textuelle du Vaisseau.
* @return	un string du modèle et capacité du Vaisseau.
*/
string Vaisseau::toString() const {
	return modele + " " + to_string(capacite);
}

/**
* Surcharge de l’opérateur ==.
* @param	_vaisseau : le second vaisseau avec lequel comparer.
* @return	true si les modèles sont les mêmes, false sinon.
*/
bool Vaisseau::operator==(Vaisseau _vaisseau) {
	return this->modele == _vaisseau.modele;
}