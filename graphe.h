#pragma once
#include <string>
#include <vector>
#include "planete.h"
#include "route.h"
#include "arete.h"

constexpr short INIT = 100;
class Graphe
{
private:
	Arete matrice[INIT][INIT];						// Matrice d’adjacence.
	short nbElements;								// Nombre d’élements 
	float limite;									// La capacité en carburant du vaisseau utilisant ce graphe. Symbolisant donc sa limite pour atteindre les planètes.
	vector<Planete>* planetes;						// Pointeur vers le vector des planètes.
public:
	Graphe(vector<Planete>*, const float);			// Constructeur de Graphe.
	~Graphe();										// Destructeur de Graphe.
	short getPlaneteidx(const string) const;		// Getter de l’index d’une Planète.
	void ajouterArete(const short, const short);	// Ajouter une arète à la matrice.
	void retirerArete(const short, const short);	// Retirer une arète à la matrice.
	string toStringMatrice(bool, bool) const;		// Représentation textuelle de la Matrice.
};