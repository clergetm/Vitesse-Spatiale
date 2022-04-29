#pragma once
#include <array>
#include <string>
#include <vector>
#include "arete.h"
#include "planete.h"
#include "route.h"

/**
* Implémentation de la structure de données Graphe.
* Les relations entre les sommets d’un graphe sont représentées dans la matrice d’adjacence.
*/
class Graphe
{
private:
	vector<vector<Arete>> matrice;								// Matrice d’adjacence.
	short nbElements;											// Nombre d’élements 
	float limite;												// La capacité en carburant du vaisseau utilisant ce graphe. Symbolisant donc sa limite pour atteindre les planètes.
	vector<Planete>* planetes;									// Pointeur vers le vector des planètes.
	vector<bool> visites;										// Array des (index des) planètes visitées.
	void aideDFS(const string, const string, Route&, short&);	// Fonction Récursif du parcours DFS.
	short getMinDistanceIdx(vector<float>&);					// Getter de l'indice du poids minimal dans la liste des poids.
	bool estCompletementVisite() const;							// Vérifier que la liste a été complètement visité.
public:
	Graphe(vector<Planete>*, const float);						// Constructeur de Graphe.
	~Graphe();													// Destructeur de Graphe.
	short getPlaneteidx(const string) const;					// Getter de l’index d’une Planète.
	vector<Planete>* getPlanetesptr();							// Getter du pointeur du vector de planètes.
	void hydraterMatrice(vector<Planete>*, float);				// Mettre à jour la Matrice et les informations du graphe.
	void ajouterArete(const short, const short);				// Ajouter une arète à la matrice.
	void retirerArete(const short, const short);				// Retirer une arète à la matrice.
	void retirerArete(const string, const string);				// Retirer les arètes de la matrice entre deux nations.
	string toStringMatrice(bool, bool) const;					// Représentation textuelle de la Matrice.
	void nettoyerVisite();										// Réinitialiser la liste des visites.
	Route DFS(const string, const string);						// Parcours DFS du Graphe.
	Route dijkstra(const string, const string, const string);	// Parcours Dijkstra du Graphe.
};