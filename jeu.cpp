#include "jeu.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void Jeu::ouverture_transaction(string _fichierTransaction) {

	ifstream fin(_fichierTransaction); //Lecture
	char caractere;

	string nomFichierSystemeStellaire;
	string nomFichierTypesVaisseau;
	string typeVaisseau;
	string PlaneteS;
	string PlaneteD;
	


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
		case '/':{


				break;
			}

		case '&':{

				break;
			}

		}

	}


}

void Jeu::ouverture_stellaire(string _fichierPlanetes) {}

void Jeu::ouverture_vaisseau(string _fichierVaisseaux) {}