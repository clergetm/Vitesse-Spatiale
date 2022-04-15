#pragma once
#include <string>
using namespace std;

class Vaisseau
{
private:
	string modele;					// Modèle du Vaisseau.
	float capacite;					// Capacité en carburant du Vaisseau.
public:
	Vaisseau(string, float);		// Constructeur par défaut.
	~Vaisseau();					// Destructeur par défaut.
	string getModele() const;		// Getter de modele. 
	float getCapacite() const;		// Getter de la capacite en carburant.
	string toString() const;		// Obtenir une représentation textuelle.
	bool operator == (Vaisseau);	// Surcharge de l'opérateur == pour les comparaisons.
};
