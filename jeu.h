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
	vector<string> conflits;														// Vector des conflits entre nations de ce jeu.
	vector<Vaisseau> vaisseaux;														// Vector des vaisseaux du jeu.
	vector<Planete> planetes;														// Vector des planètes du jeu.
	bool ouverture_planetes(string);												// Ouvrir un fichier de planetes.
	bool ouverture_vaisseaux(string);												// Ouvrir un fichier de vaisseaux.
	void ajouter_conflit(string, string);											// Ajouter un conflit entre deux nations
	void planifierRoute(const string, const string, const string, const string);	// Executer un parcours avec les différents informations.
	void menuCommandes(bool);														// Lancer le menu des commandes.
public:
	Jeu();																			// Constructeur par défaut.
	~Jeu();																			// Destructeur par défaut.
	bool ouverture_transactions(string);											// Ouvrir un fichier de transaction.
	void menu();																	// Lancer le menu principal.
	void afficherTout();															// Afficher toutes les informations en mémoire.
};