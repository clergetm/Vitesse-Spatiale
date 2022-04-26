#include "jeu.h"
#include <string>
#include <iostream>
#include <fstream>
#include "planete.h"

using namespace std;


/**
* Constructeur par défaut.
*/
Jeu::Jeu(){}

/**
* Destructeur par défaut
*/
Jeu::~Jeu(){}


void Jeu::ouverture_transaction(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture
	char caractere;

	string nomFichierSystemeStellaire;
	string nomFichierTypesVaisseau;
	string typeVaisseau;
	string PlaneteS;
	string PlaneteD;
	string A;
	string B;


	while (fin >> caractere) {
		switch (caractere) {

		
		case '#': {
			fin >> caractere;
			//Charge un système en mémoire
			if (caractere == 'P') {
				cout << "Charge d'un système stellaire mémoire \n" << endl;
				fin >> nomFichierSystemeStellaire;
				ouverture_stellaire(nomFichierSystemeStellaire);

			}

			//Charger les types de vaisseau en mémoire
			if (caractere == 'V') {
				cout << "Charge les différents type de vaisseau en mémoire \n" << endl;
				fin >> nomFichierTypesVaisseau;
				ouverture_vaisseau(nomFichierTypesVaisseau);

			}
			break;
		}
			
			//Affichage 
		case '?': {
			fin >> caractere;
			if (caractere == '1') {

				fin >> typeVaisseau >> PlaneteS >> PlaneteD;
				cout << "Existe-il une route entre les planètes" << PlaneteS << "et" << PlaneteD << "pour un vaisseau de type" << typeVaisseau << "\n" << endl;
			}
			if (caractere == '2') {

				fin >> typeVaisseau >> PlaneteS >> PlaneteD;
				cout << "Avec le vaisseau" << typeVaisseau << "la disctance la plus courte entre " << PlaneteS << "et" << PlaneteD << "est : " << "\n";

			}
			if (caractere == '3') {
				fin >> typeVaisseau >> PlaneteS >> PlaneteD;
				cout << "Avec le vaisseau" << typeVaisseau << "la distance la moins dispendieux entre " << PlaneteS << "et" << PlaneteD << "est : " << "\n";

			}
			break;
		}
				//
		case '/':{
					
			fin >> A >> B;
			cout << "Conflit spatiale entre les nations \n" << endl;
			ajouter_conflit(A, B);
				break;
			}

		case '&':{

			for (Planete p : planetes) {

				cout << p.getNomPlanete () << " ";
				cout << p.getX() << " ";
				cout << p.getY() << " ";
				cout << p.getPopulation() << " ";
				cout << p.getNation() << " ";
				cout << p.getPrixCarburant() << "\n";

			}

			for (Vaisseau v : vaisseaux) {

					cout << v.getModele() << " ";
					cout << v.getCapacite() << "\n";
				
			}

			for (string c : conflits) {

				cout << c << "\n";

			}
				break;
			}
		}
	}
}

void Jeu::ouverture_stellaire(string _fichierPlanetes) {

	ifstream fin(PATH+_fichierPlanetes); //Lecture

		// Variables composant d'une planète
	string nomPlanete;
	float x;
	float y;
	int population;
	string nation;
	float prixCarburant;

	// Tant que l’on peut recupérer les informations
	while (fin >> nomPlanete) {
		fin >> x >> y >> population >> nation >> prixCarburant;
		planetes.push_back(Planete(nomPlanete, x, y, population, nation, prixCarburant));
	}

	// Fermer la lecture du fichier
	fin.close();

}

void Jeu::ouverture_vaisseau(string _fichierVaisseaux) {

	ifstream fin(PATH+_fichierVaisseaux); //Lecture

		// Variables composant d'une planète
	string Modele;
	float Capacite;


	// Tant que l’on peut recupérer les informations
	while (fin >> Modele) {
		fin >> Capacite;
		vaisseaux.push_back(Vaisseau(Modele, Capacite,&(this->planetes)));
	}

	// Fermer la lecture du fichier
	fin.close();

}

void Jeu::ajouter_conflit(string _A, string _B) {

	string c = _A + "/" + _B;
	conflits.push_back(c);
	//systeme.retirerArete(_A, _B);

}
