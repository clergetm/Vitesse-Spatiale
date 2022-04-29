#pragma once
#include <string>
#include <vector>
#include "graphe.h"
#include "planete.h"
using namespace std;

/**
* Implementation des vaisseaux.
* Les vaisseaux determine les relations entre les sommets d’un graphe.
* La distance entre deux sommets ne peut pas être supérieur à la capacité en carburant du vaisseau.
*/
class Vaisseau
{
private:
	string modele;										// Modèle du Vaisseau.
	float capacite;										// Capacité en carburant du Vaisseau.
	Graphe systeme;										// Système empruntable par le Vaisseau.
public:
	Vaisseau(vector<Planete>*);							// Constructeur par défaut.
	Vaisseau(string, float, vector<Planete>*);			// Constructeur de Vaisseau.
	~Vaisseau();										// Destructeur par défaut.
	string getModele() const;							// Getter de modele. 
	float getCapacite() const;							// Getter de la capacite en carburant.
	Graphe& getSysteme();								// Getter du Systeme.
	string toString() const;							// Obtenir une représentation textuelle.
	friend ostream& operator<< (ostream&, Vaisseau&);	// Surcharge de l’opérateur <<.
	friend istream& operator>> (istream&, Vaisseau&);	// Surcharge de l’opérateur >>.
};
