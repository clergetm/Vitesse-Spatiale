#include "planete.h"
using namespace std;

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
*/
Planete::Planete() {
	this->nomPlanete ="";
	this->x = 0;
	this->y = 0;
	this->population = 0;
	this->nation = "";
	this->prixCarburant = 0;
}

/**
* Constructeur de Planete.
* @param	_nomPlanete :		le nom de la Planète.
* @param	_x :				la coordonnée x de la Planète.
* @param	_y :				la coordonnée y de la Planète.
* @param	_population :		la population de la Planète.
* @param	_nation :			la nation de la Planète.
* @param	_prixCarburant :	le prix du Carburant sur la Planète.
*/
Planete::Planete(string _nomPlanete, float _x, float _y, int _population, string _nation, float _prixCarburant ){
	this->nomPlanete = _nomPlanete;
	this->x = _x;
	this->y = _y;
	this->population = _population;
	this->nation = _nation;
	this->prixCarburant = _prixCarburant;
}

/**
* Destructeur par défaut.
*/
Planete::~Planete(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du nom de la planète.
* @return	le nom de la planète.
*/
string Planete::getNomPlanete() const { return this->nomPlanete; }

/**
* Getter de la coordonnée x.
* @return	la coordonnée x de la planète.
*/
float Planete::getX() const { return this->x; }

/**
* Getter de la coordonnée y.
* @return	la coordonnée y de la planète.
*/
float Planete::getY() const { return this->y; }

/**
* Getter de la population.
* @return	la population de la planète.
*/
int Planete::getPopulation() const { return this->population; }

/**
* Getter de la nation.
* @return	la nation de la planète.
*/
string Planete::getNation() const { return this->nation; }

/**
* Getter du prix du carburant.
* @return	le prix du carburant de la planète.
*/
float Planete::getPrixCarburant() const { return this->prixCarburant; }

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Obtenir une représentation textuelle de la Planete.
* @return	un string avec les éléments de la Planete.
*/
string Planete::toString() const {
	return nomPlanete + " " + to_string((short)x) + " " + to_string((short)y) + " "
		+ to_string(population) + " " + nation + " " + to_string(prixCarburant);
}

/*
* Surcharge de l’opérateur <<. Retour du toString de Planete.
* @param _out :			le stream de output.
* @param _planete :		la Planete à représenter.
* @return				le stream à jour.
*/
ostream& operator<<(ostream& _out, Planete& _planete)
{
	_out << _planete.toString();
	return _out;
}

/*
* Surcharge de l’opérateur >>. Récupération des informations formant une Planete.
* @param _in :			le stream d’input.
* @param _planete :		la Planete à modifier.
* @return				Le stream à jour.
*/
istream& operator>>(istream& _fin, Planete& _planete)
{
	_fin >> _planete.nomPlanete >> _planete.x >> _planete.y >> _planete.population >> _planete.nation >> _planete.prixCarburant;
	return _fin;
}