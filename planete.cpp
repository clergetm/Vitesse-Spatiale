#include "planete.h"
#include <iostream>
using namespace std;


// Constructeur par défaut.

Planete::Planete(string _nomPlanete, float _x, float _y, int _population, string _nation, float _prixCarburant ){
	this->nomPlanete = _nomPlanete;
	this->x = _x;
	this->y = _y;
	this->population = _population;
	this->nation = _nation;
	this->prixCarburant = _prixCarburant;
}

// Destructeur par défaut

Planete::~Planete(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du nom de la planète.
* @return	string du nom de la planète.
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



bool Planete::operator==(Planete _planete) {
	return this->nomPlanete == _planete.nomPlanete;
}