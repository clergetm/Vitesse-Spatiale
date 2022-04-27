#include "jeu.h"
#include <string>
#include <iostream>
#include <fstream>
#include "planete.h"

using namespace std;

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
 * Constructeur par défaut.
 */
Jeu::Jeu() {}

/**
 * Destructeur par défaut
 */
Jeu::~Jeu() {}

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
 * Ouverture et execution d'un fichier de transactions.
 * Les transactions ne peuvent pas s'exécuter si le fichier des vaisseaux doit être lu avant le fichier des planètes.
 * Le programme nécessite les planètes afin d'instancier les vaisseaux.
 *
 * @param	_fichierTransaction : Le nom du fichier de Transaction.
 */
void Jeu::ouverture_transaction(string _fichierTransaction) {

    ifstream fin(_fichierTransaction); //Lecture

    // Variables utilisées pour la transaction
    char caractere;
    string nomFichierSystemeStellaire, nomFichierVaisseaux;
    string typeVaisseau, planeteS, planeteD, nationA, nationB;

    // Tant qu'on peut lire le premier caractère de chaque ligne.
    while (fin >> caractere) {
        switch (caractere) {
            // On souhaite lire un autre fichier txt
            case '#': {

                // Il faut savoir quel autre fichier est à lire, un fichier de Planetes, ou un fichier de Vaisseaux.
                fin >> caractere;
                //Charge un système en mémoire
                if (caractere == 'P') {
                    cout << "Charge les différentes planètes en mémoire \n" << endl;
                    fin >> nomFichierSystemeStellaire;
                    ouverture_planetes(nomFichierSystemeStellaire);
                }

                //Charger les types de vaisseau en mémoire
                if (caractere == 'V') {
                    cout << "Charge les différents vaisseaux en mémoire \n" << endl;
                    fin >> nomFichierVaisseaux;
                    ouverture_vaisseaux(nomFichierVaisseaux);
                }
                break;
            }

            // On souhaite exécuter trouver une route à partir d'une requête.
            case '?': {
                // Il faut savoir de quel type de requête il s'agit.
                fin >> caractere;

                // Il s'agit de trouver simplement un chemin entre deux planètes.
                if (caractere == '1') {

                    fin >> typeVaisseau >> planeteS >> planeteD;
                    cout << "Existe-t-il une route entre les planètes " << planeteS << " et " << planeteD << " pour un vaisseau de type " << typeVaisseau << "?"<< endl;
                    planifierRoute("DFS",typeVaisseau, planeteS, planeteD);

                }

                // Il s'agit de trouver le plus court chemin entre deux planètes.
                if (caractere == '2') {

                    fin >> typeVaisseau >> planeteS >> planeteD;
                    cout << "Existe-t-il une route la plus courte entre les planètes " << planeteS << " et " << planeteD << " pour un vaisseau de type " << typeVaisseau << "?" << endl;
                //    planifierRoute("Dijkstra-distance", typeVaisseau, planeteS, planeteD);
                    cout << " NE FONCTIONNE PAS POUR L INSTANT" << endl;
                }

                // Il s'agit de trouver le chemin le moins dispendieux entre deux planètes.
                if (caractere == '3') {
                    fin >> typeVaisseau >> planeteS >> planeteD;
                    cout << "Existe-t-il une route la moins dispendieux entre les planètes " << planeteS << " et " << planeteD << " pour un vaisseau de type " << typeVaisseau << "?" << endl;
                //    planifierRoute("Dijkstra-cout", typeVaisseau, planeteS, planeteD);
                    cout << " NE FONCTIONNE PAS POUR L INSTANT" << endl;

                }
                break;
            }
            // On souhaite ajouter un conflit entre deux nations.
            case '/': {

                fin >> nationA >> nationB;
                cout << "Conflit spatiale entre les nations \n" << endl;
                ajouter_conflit(nationA, nationB);
                break;
            }
            // On souhaite afficher les informations en mémoire.
            case '&': {
                cout << "Affichages des informations en mémoire " << '\n';
                cout << "_________________________________________" << '\n';

                cout << "Planètes : " << '\n';
                for (Planete p : planetes) {
                    cout << " - " << p.toString() << "\n";
                }
                cout << "______________________" << '\n';
                cout << "Vaisseaux : " << '\n';

                for (Vaisseau v : vaisseaux) {
                    cout << " - " << v.toString() << "\n";
                }

                cout << "______________________" << '\n';
                cout << "Conflits : " << '\n';
                for (string c : conflits) {
                    cout << " - " << c << "\n";
                }
                cout << "_________________________________________" << '\n' << endl;


                break;
            }
            }
    }
}

/**
* Ouverture d'un fichier de planetes.
* @param    _fichierPlanetes : Le nom du fichier des Planetes.
*/
void Jeu::ouverture_planetes(string _fichierPlanetes) {

    ifstream fin(_fichierPlanetes); //Lecture

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

/**
* Ouverture d'un fichier de vaisseaux.
* @param    _fichierVaisseaux : Le nom du fichier des Vaisseaux.
*/
void Jeu::ouverture_vaisseaux(string _fichierVaisseaux) {

    ifstream fin(_fichierVaisseaux); //Lecture

    // Variables composant d'une planète
    string Modele;
    float Capacite;

    // Tant que l’on peut recupérer les informations
    while (fin >> Modele) {
        fin >> Capacite;
        vaisseaux.push_back(Vaisseau(Modele, Capacite, &planetes));
    }

    // Fermer la lecture du fichier
    fin.close();

}

/**
* Ajouter un conflit entre deux nations.
* @param    _nationA : La première nation.
* @param    _nationB : La seconde nation.
*/
void Jeu::ajouter_conflit(string _nationA, string _nationB) {

    // Ajouter ce conflit à la liste des conflits.
    string c = _nationA + "/" + _nationB;
    conflits.push_back(c);

    // Mettre à jour les graphes des vaisseaux.
    for (Vaisseau v : vaisseaux) {
        v.getSysteme().retirerArete(_nationA, _nationB);
    }

}

/**
* @param    _parcours   : Le type de parcours emprunté.
* @param    _modele     : Le modèle du vaisseau.
* @param	_depart     : La planète source du déplacement.
* @param	_arrivee    : La planète destination à atteindre.
*/
void Jeu::planifierRoute(const string _parcours, const string _modele, const string _depart, const string _arrivee) {
    Route res;
    Vaisseau* v = nullptr;

    // Vérifier que le modèle de vaisseau existe 
    for (short _idx = 0; _idx < (short)vaisseaux.size(); _idx++) {
        if (vaisseaux.at(_idx).getModele() == _modele) {
            v = &(vaisseaux.at(_idx));
        }
    }
    if (v == nullptr) {
        cout << "Ce modèle n'existe pas." << endl;
        return;
    }

    if (_parcours == "DFS") {
        res = v->getSysteme().DFS(_depart, _arrivee);
    }
    else if (_parcours == "Dijkstra-distance") {
        res = v->getSysteme().dijkstra(_depart, _arrivee, "distance");
    }
    else if (_parcours == "Dijkstra-cout") {
        res = v->getSysteme().dijkstra(_depart, _arrivee, "cout");
    }
    else {
        cout << "Ce parcours n'existe pas" << endl;
        return;
    }

    if (res.estVide()) {
        cout << "Aucune route n'existe entre les planètes " << _depart << " et " << _arrivee << '\n';
        cout << "Pour le modèle : " << _modele << endl;
        return;
    }

    cout << "Il existe une route entre les planètes " << _depart << " et " << _arrivee << '\n';
    cout << "Pour le modèle : " << _modele << '\n';
    cout << res.toString() << endl;

}