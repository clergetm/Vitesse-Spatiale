#pragma once
#include <string>
#include <vector>
#include "graphe.h"
#include "planete.h"
using namespace std;

class Vaisseau
{
private:
	string modele;								// Modèle du Vaisseau.
	float capacite;								// Capacité en carburant du Vaisseau.
	Graphe systeme;								// Système empruntable par le Vaisseau.
public:
	Vaisseau(string, float, vector<Planete>*);	// Constructeur par défaut.
	~Vaisseau();								// Destructeur par défaut.
	string getModele() const;					// Getter de modele. 
	float getCapacite() const;					// Getter de la capacite en carburant.
	Graphe& getSysteme();						// Getter du Systeme.
	string toString() const;					// Obtenir une représentation textuelle.
	bool operator == (Vaisseau);				// Surcharge de l'opérateur == pour les comparaisons.
};
