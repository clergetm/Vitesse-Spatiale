#pragma once
#include <string>
#include <vector>
#include "graphe.h"
#include "planete.h"
#include "vaisseau.h"
using namespace std;

class Jeu
{
private:
	const string PATH = "Fichiers/";	// 
	Graphe systeme;						// Graphe Initial représentant les relations entre les planètes.
	vector<string> conflits;			// Vector des conflits entre nations de ce jeu.
	vector<Vaisseau> vaisseaux;			// Vector des vaisseaux du jeu.
	vector<Planete> planetes;			// Vector des planètes du jeu.
public:
	Jeu();
	~Jeu();

	void ajouter_conflit(string, string);
	void ouverture_transaction(string);
	void ouverture_stellaire(string);
	void ouverture_vaisseau(string);


	friend ostream& operator<< (ostream& _out, Planete& _planete);	// Surcharge de l'opérateur <<
};

