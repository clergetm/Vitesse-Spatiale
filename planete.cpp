#include "planete.h"
using namespace std;

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
* @param	_nomPlanete : le nom de la Planète.
* @param	_x : la coordonnée x de la Planète.
* @param	_y : la coordonnée y de la Planète.
* @param	_population : la population de la Planète.
* @param	_nation : la nation de la Planète.
* @param	_prixCarburant : le prix du Carburant sur la Planète.
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
* Destructeur par défaut
*/
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

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Obtenir une représentation textuelle de la Planete.
* @return	un string avec les éléments de la Planete.
*/
string Planete::toString() const {
	return nomPlanete + " " + to_string(x) + " " + to_string(y) + " "
		+ to_string(population) + " " + nation + " " + to_string(prixCarburant);
}

/**
* Surcharge de l’opérateur ==.
* @param	_planete : la seconde planete avec laquelle comparer.
* @return	true si les noms sont les mêmes, false sinon.
*/
bool Planete::operator==(Planete _planete) {
	return this->nomPlanete == _planete.nomPlanete;
}



