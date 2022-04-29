#pragma once
#include <iostream>
#include <string>
using namespace std;

/**
* Implémentation des Planetes.
* 
* Une Planete représente un Sommet dans un Graphe.
* Chaque planète est identifiée par un nom unique. 
* Son emplacement est determiné par x et y.
*/
class Planete
{
private:
	string nomPlanete;									// Nom de la Planète.
	float x;											// Coordonnée x de la Planète.
	float y;											// Coordonnée y de la Planète.
	int population;										// Le nombre d’individus sur la Planète.
	string nation;										// Le nom de la nation dirigeant la Planète.
	float prixCarburant;								// le prix du Carburant sur la Planète.
public:
	Planete();											// Constructeur par défaut.
	Planete(string, float, float, int, string, float);	// Constructeur de la Planète.
	~Planete();											// Destructeur par défaut de la Planète.
	string getNomPlanete() const;						// Getter du nom de la Planète.
	float getX() const;									// Getter de la coordonnée x de la Planète.
	float getY() const;									// Getter de la coordonnée x de la Planète.
	int getPopulation() const;							// Getter de la population de la Planète.
	string getNation() const;							// Getter de la nation de la Planète.
	float getPrixCarburant() const;						// Getter du prix du Carburant sur la Planète.
	string toString() const;							// Représentation textuelle des éléments décrivant la Planète.
	friend ostream& operator<< (ostream&, Planete&);	// Surcharge de l’opérateur <<.
	friend istream& operator>> (istream&, Planete&);	// Surcharge de l’opérateur >>.
};
