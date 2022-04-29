#pragma once
#include <deque>
#include "arete.h"
#include "planete.h"

/**
* Représentation des routes séparant une planète source à une planète destination. 
* Une route peut être obtenu via le parcours DFS ou dijkstra.
*/
class Route
{
private:
	deque<Arete> etapes;							// file des étapes.
public:
	Route();										// Constructeur par défaut.
	~Route();										// Destructeur par défaut.
	Planete* depart() const;						// Getter du point de départ.
	Planete* arrivee() const;						// Getter du point d’arrivée.
	bool estVide() const;							// Vérifier si cette route possède des étapes ou non.
	float cout() const;								// Calcul du cout de cette route.
	float distance() const;							// Calcul de la distance parcourue avec cette route.
	void modifierEtape(const short, const Arete);	// Modification d’une étape à un emplacement.
	void ajouterEtape(const Arete);					// Insertion d’une étape à la fin.
	string toString() const;						// Représentation textuelle de la route.
};