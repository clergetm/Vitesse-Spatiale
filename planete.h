#pragma once
#include <string>
#include <iostream>
using namespace std;

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
	Planete(string, float, float, int, string, float);	// Constructeur par défaut de la Planète.
	~Planete();											// Destructeur par défaut de la Planète.
	string getNomPlanete() const;						// Getter du nom de la Planète.
	float getX() const;									// Geter de la coordonnée x de la Planète.
	float getY() const;									// Getter de la coordonnée x de la Planète.
	int getPopulation() const;							// Getter de la population de la Planète.
	string getNation() const;							// Getter de la nation de la Planète.
	float getPrixCarburant() const;						// Getter du prix du Carburant sur la Planète.
	string toString() const;							// Représentation textuelle des éléments décrivant la Planète.
	bool operator == (Planete _planete);				// Surcharge de l'opérateur == pour les comparaisons.	
};
