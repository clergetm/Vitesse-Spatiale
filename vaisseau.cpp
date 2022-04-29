#include "vaisseau.h"
using namespace std;

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
*/
Vaisseau::Vaisseau(vector<Planete>* _planetes = nullptr):modele(""),capacite(0), systeme(_planetes,this->capacite) {}

/**
* Constructeur de Vaisseau.
* @param	_modele :	le nom du vaisseau.
* @param	_capacite : la capacité en carburant du vaisseau.
*/
Vaisseau::Vaisseau(string _modele, float _capacite, vector<Planete>* _planetes = nullptr): modele(_modele), capacite(_capacite), systeme(_planetes,this->capacite) {}

/**
* Destructeur par défaut.
*/
Vaisseau::~Vaisseau(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du Modèle du Vaisseau.
* @return	le modèle du vaisseau.
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
	return modele + " " + to_string((short)capacite);
}

/*
* Surcharge de l’opérateur <<. Retour du toString de Vaisseau.
* @param _out :			le stream de output.
* @param _vaisseau :	le Vaisseau à représenter.
* @return				le stream à jour.
*/
ostream& operator<<(ostream& _out, Vaisseau& _vaisseau)
{
	_out << _vaisseau.toString();
	return _out;
}

/*
* Surcharge de l’opérateur >>. Récupération des informations formant un Vaisseau.
* @param _in :			le stream d’input.
* @param _vaisseau :	le Vaisseau à modifier.
* @return				Le stream à jour.
*/
istream& operator>>(istream& _fin, Vaisseau& _vaisseau)
{
	// On récupère les informations
	_fin >> _vaisseau.modele >> _vaisseau.capacite;

	// On met à jour le systeme de ce vaisseau.
	_vaisseau.getSysteme().hydraterMatrice(_vaisseau.getSysteme().getPlanetesptr(),_vaisseau.getCapacite());
	return _fin;
}