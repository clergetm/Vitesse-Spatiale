#include "jeu.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
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

//// MENU /////////

/**
* Menu principal du jeu, permettant au joueur de lancer un fichier de transactions ou de lancer le menu des commandes.
*/
void Jeu::menu() {

    char caractere;
    string parametre;
    bool transactionsEffectue = false;
    do {

        // Réinitialisation de tous les éléments.
        cin.clear();
        system("cls");

        // Afficher les options au joueur.
        cout << "Vous pouvez choisir parmi ces deux options" << '\n';
        cout << " [a, 1] - Ouvrir un fichier de transactions." << '\n';
        cout << " [b, 2] - Executer vos propres commandes." << '\n';
        cout << " [q, 0] - Quitter." << '\n';
        cout << "Votre choix: "; cin >> caractere;

        // Premier switch pour permettre au joueur d'utiliser un fichier de transaction ou de jouer par lui même
        switch (caractere) {
            // Le joueur veut lancer un fichier de transactions.
        case 'a': case '1': {
            cout << "  - Entrer le path du fichier de transactions que vous souhaitez exécuter." << '\n';
            cin >> parametre;
            // On lance les transactions.
            transactionsEffectue = ouverture_transactions(parametre);
            break;
        };

                // Le joueur veut executer ses propres commandes.
        case 'b': case '2': {
            cout << " - Vous allez maintenant pouvoir executer vos propres commandes." << '\n';
            bool keep = false;
            // On demande au joueur, avant d'afficher le menu des commandes, s'il veut conserver les informations des transactions.
            if (transactionsEffectue) {
                cout << "  - Voulez-vous conserver les planètes, vaisseaux et conflits créés par les transactions ? [Y/n]: ";
                cin >> caractere;
                if (caractere == 'Y') {
                    cout << "  - Les informations seront conservées" << '\n';
                    keep = true;
                }
                else {
                    cout << "  - Les informations ne seront pas conservées" << '\n';
                    keep = false;
                }
            }

            // Le joueur rentre dans le menu des Commandes.
            menuCommandes(keep);
            break;
        };

                // Le joueur quitte le menu principal.
        case 'q': case '0': {
            cout << " - Vous allez quitter le menu principal." << '\n';
            caractere = 'q';
            break;
        };

                // Cas par défaut.
        default: {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        };
        system("pause");
    } while (caractere != 'q');
}

/**
* Méthode Initiant un menu dans la console permettant à l'utilisateur de lancer ses propres commandes.
* @param    _keep : Les données déjà en mémoire sont conservées si true. Supprimées sinon.
*/
void Jeu::menuCommandes(bool _keep) {


    char commande = ' ', typeCommande = ' ';
    string parametresSTR;
    vector<string> parametres;
    bool planetesEnMemoire = _keep;
    bool vaisseauxEnMemoire = _keep;

    // On réinitialise les informations si nécessaire.
    if (!_keep) {
        planetes.clear();
        vaisseaux.clear();
        conflits.clear();
    }

    do {
        // Réinitialisation de tous les éléments de paramètres et affichages.
        parametres.clear();
        cin.clear();
        system("cls");

        // Afficher les options au joueur.
        cout << "Vous pouvez maintenant indiquer votre commandes" << '\n';
        if (!planetesEnMemoire) {
            cout << "#P FICHIER // Charge un système stellaire en mémoire (fichiers de planète)." << '\n';
        }
        else if (!vaisseauxEnMemoire) {
            cout << "#P FICHIER // Charge un système stellaire en mémoire (fichiers de planète)." << '\n';
            cout << "#V FICHIER // Charge les types de vaisseau en mémoire (fichier vaisseau)." << '\n';
        }

        else {
            cout << "#P FICHIER // Charge un système stellaire en mémoire (fichiers de planète)." << '\n';
            cout << "#V FICHIER // Charge les types de vaisseau en mémoire (fichier vaisseau)." << '\n';
            cout << "?1 V S D   // Affiche la réponse à la question : existe-t-il une route entre les planètes S et D pour un vaisseau de type V." << '\n';
            cout << "?2 V S D   // Affiche le plus court chemin ainsi que la distance totale que peut parcourir le vaisseau V pour se rendre de la planète S à D." << '\n';
            cout << "?3 V S D   // Affiche le chemin et le coût du trajet le moins dispendieux que peut suivre le vaisseau V pour se rendre de la planète S à D." << '\n';
            cout << "/ N1 N2    // Applique un scénario de conflit spatial entre les nations N1 et N2." << '\n';
            cout << "&          // Affiche toutes les planètes (info des planètes), tous les types de vaisseau (info des vaisseaux) et tous les conflits entre deux nations." << '\n';

        }
        cout << "[q, 0] - Quitter." << '\n';

        // On récupère les choix (et paramètres) du joueur.
        cout << "Votre choix: " << '\n';
        getline(cin >> ws, parametresSTR);

        // Puis on transforme la réponse en vector.
        stringstream streamParam(parametresSTR);
        string temp;
        while (streamParam >> temp) {
            parametres.push_back(temp);
        }

        // On vérifie qu'il y a des paramètres
        if (!parametres.empty()) {

            // On récupère la commande
            commande = parametres[0][0];
            // On tri en fonction de la taille de la commande (1 ou 2 char).
            if (parametres[0].length() == 2) {
                typeCommande = parametres[0][1];
            }

            // Si les planètes ne sont pas chargées et que la commande pour charger les planètes n'est pas donnée.
                                                                                 // Ne s'applique pas si on souhaite sortir du menu
            if (!planetesEnMemoire && (!(commande == '#' && typeCommande == 'P')) && !(commande == 'q' || commande == '0')) {
                // On passe par la case default.
                cout << " - Vous devenez générer les planètes avant de générer les vaisseaux." << '\n';
                commande = 'd';
            }

        }
        // Sinon on passe par la case default.
        else {
            cout << "Veuillez ajouter des paramètres avant d'appuyer sur entrée." << '\n';
            commande = 'd';

        }


        switch (commande) {
        case '#': {
            // On vérifie qu'il y a le bon nombre de paramètres
            // Le if est fait ainsi pour une meilleure lisibilité.
            if ((short)parametres.size() < 2) {
                cout << " - FICHIER est manquant." << '\n';
                break;
            }

            // On vérifie s'il on veut ouvrir un fichier de planètes ou de vaisseaux.
            if (typeCommande == 'P') {
                planetesEnMemoire = ouverture_planetes(parametres[1]);
            }

            else if (typeCommande == 'V') {
                vaisseauxEnMemoire = ouverture_vaisseaux(parametres[1]);
            }
            else {
                cout << " - Le type de commande indiqué n'est pas le bon." << '\n';
                cout << "  - Veuillez indiquer #P ou #V" << '\n';
            }

            break;

        }
        case '?': {
            // On vérifie qu'il y a le bon nombre de paramètre
            // Le if est fait ainsi pour une meilleure lisibilité.
            if ((short)parametres.size() < 4) {
                cout << " - V et/ou S et/ou D est manquant." << '\n';
                break;
            }
            // Il s'agit de trouver simplement un chemin entre deux planètes.
            if (typeCommande == '1') {
                planifierRoute("DFS", parametres[1], parametres[2], parametres[3]);
            }

            // Il s'agit de trouver le plus court chemin entre deux planètes.
            else if (typeCommande == '2') {
                planifierRoute("Dijkstra-distance", parametres[1], parametres[2], parametres[3]);
            }

            // Il s'agit de trouver le chemin le moins dispendieux entre deux planètes.
            else if (typeCommande == '3') {
                planifierRoute("Dijkstra-cout", parametres[1], parametres[2], parametres[3]);
            }
            else {
                cout << " - Le type de parcours indiqué n'est pas le bon." << '\n';
                cout << "  - Veuillez indiquer ?1 ou ?2 ou ?3" << '\n';
            }
            break;
        }

        case '/': {
            if ((short)parametres.size() < 3) {
                cout << " - N1 et/ou N1 est manquant." << '\n';
                break;
            }
            ajouter_conflit(parametres[1], parametres[2]);
            break;
        }
        case '&': {
            afficherTout();
            break;
        }
        case 'q': case '0': {
            cout << " - Vous allez quitter le menu des Commandes." << '\n';
            commande = 'q';
            break;
        }

        case 'd': default: {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        };

        system("pause");
    } while (commande != 'q');
}

//// OUVERTURES ///
/**
 * Ouverture et execution d'un fichier de transactions.
 * Les transactions ne peuvent pas s'exécuter si le fichier des vaisseaux doit être lu avant le fichier des planètes.
 * Le programme nécessite les planètes afin d'instancier les vaisseaux.
 *
 * @param	_fichierTransaction : Le nom du fichier de Transaction.
* @return   true si l'ouverture et la lecture se font sans encombre. False sinon.
 */
bool Jeu::ouverture_transactions(string _fichierTransactions) {

    ifstream fin(_fichierTransactions); //Lecture

    if (!fin) {
        cout << "Le path fourni : "<< _fichierTransactions <<", ne mène pas à un fichier." << endl;
        return false;
    }
    // Variables utilisées pour la transaction
    char caractere;
    string nomFichierSystemeStellaire, nomFichierVaisseaux;
    string typeVaisseau, planeteS, planeteD, nationA, nationB;

    try {
        cout << "Lecture en cours de : " << _fichierTransactions << '\n';
        // Tant qu'on peut lire le premier caractère de chaque ligne.
        while (fin >> caractere) {
            switch (caractere) {
                // On souhaite lire un autre fichier txt
                case '#': {

                    // Il faut savoir quel autre fichier est à lire, un fichier de Planetes, ou un fichier de Vaisseaux.
                    fin >> caractere;
                    //Charge un système en mémoire
                    if (caractere == 'P') {
                        fin >> nomFichierSystemeStellaire;
                        if (!ouverture_planetes(nomFichierSystemeStellaire)) {
                            throw invalid_argument("Les planètes n'ont pas été chargé.");
                        }
                    }
                    //Charger les types de vaisseau en mémoire
                    else if (caractere == 'V') {
                        fin >> nomFichierVaisseaux;
                        if (!ouverture_vaisseaux(nomFichierVaisseaux)) {
                            throw invalid_argument("Les vaisseaux n'ont pas été chargé.");
                        }
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
                        planifierRoute("DFS", typeVaisseau, planeteS, planeteD);
                    }

                    // Il s'agit de trouver le plus court chemin entre deux planètes.
                    if (caractere == '2') {
                        fin >> typeVaisseau >> planeteS >> planeteD;
                        planifierRoute("Dijkstra-distance", typeVaisseau, planeteS, planeteD);
                    }

                    // Il s'agit de trouver le chemin le moins dispendieux entre deux planètes.
                    if (caractere == '3') {
                        fin >> typeVaisseau >> planeteS >> planeteD;
                        planifierRoute("Dijkstra-cout", typeVaisseau, planeteS, planeteD);
                    }
                    break;
                }
                        // On souhaite ajouter un conflit entre deux nations.
                case '/': {

                    fin >> nationA >> nationB;
                    ajouter_conflit(nationA, nationB);
                    break;
                }
                        // On souhaite afficher les informations en mémoire.
                case '&': {
                    afficherTout();
                    break;
                }
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
        cout << "Une erreur est survenue lors de la lecture du fichier de transaction." << endl;
        return false;
    }

    fin.close();
    return true;
}

/**
* Ouverture d'un fichier de planetes.
* @param    _fichierPlanetes : Le nom du fichier des Planetes.
* @return   true si l'ouverture et la lecture se font sans encombre. False sinon.
*/
bool Jeu::ouverture_planetes(string _fichierPlanetes) {

    ifstream fin(_fichierPlanetes); //Lecture
    if (!fin) {
        cout << "Le path fourni : " << _fichierPlanetes << ", ne mène pas à un fichier." << endl;
        return false;
    }

    // Variables composant d'une planète
    string nomPlanete;
    float x;
    float y;
    int population;
    string nation;
    float prixCarburant;

    try {
        cout << "Charge les différentes planètes en mémoire \n" << endl;
        // Supprimer les planétes précédentes.
        planetes.clear();
        vaisseaux.clear();
        cout << "Lecture en cours de : " << _fichierPlanetes << '\n';
        // Tant que l’on peut recupérer les informations
        while (fin >> nomPlanete) {
            fin >> x >> y >> population >> nation >> prixCarburant;
            planetes.push_back(Planete(nomPlanete, x, y, population, nation, prixCarburant));
        }
    }
    catch(exception&){
        cout << "Une erreur est survenue lors de la lecture du fichier des planetes." << endl;
        planetes.clear();
        vaisseaux.clear();
        return false;
    }


    // Fermer la lecture du fichier
    fin.close();
    return true;
}

/**
* Ouverture d'un fichier de vaisseaux.
* @param    _fichierVaisseaux : Le nom du fichier des Vaisseaux.
* @return   true si l'ouverture et la lecture se font sans encombre. False sinon.
*/
bool Jeu::ouverture_vaisseaux(string _fichierVaisseaux) {

    ifstream fin(_fichierVaisseaux); //Lecture
    if (!fin) {
        cout << "Le path fourni : " << _fichierVaisseaux << ", ne mène pas à un fichier." << endl;
        return false;
    }
    // Vérifier qu'il y a des planètes en mémoire.
    if (planetes.empty()) {
        cout << "Il faut que les planètes soient enregistrées avant d'enregistrer les vaisseaux." << endl;
        return false;
    }
    // Variables composant d'une planète
    string Modele;
    float Capacite;
    try {
        cout << "Charge les différents vaisseaux en mémoire \n" << endl;
        // Supprimer les vaisseaux précédents.
        vaisseaux.clear();
        cout << "Lecture en cours de : " << _fichierVaisseaux << '\n';
        // Tant que l’on peut recupérer les informations
        while (fin >> Modele) {
            fin >> Capacite;
            vaisseaux.push_back(Vaisseau(Modele, Capacite, &planetes));
        }
    }
    catch (exception&) {
        cout << "Une erreur est survenue lors de la lecture du fichier des vaisseaux." << endl;
        vaisseaux.clear();
        return false;
    }
    // Fermer la lecture du fichier
    fin.close();
    return true;
}

//// AUTRES ///////
/**
* Ajouter un conflit entre deux nations.
* @param    _nationA : La première nation.
* @param    _nationB : La seconde nation.
*/
void Jeu::ajouter_conflit(string _nationA, string _nationB) {

    cout << "Conflit spatiale entre les nations " << _nationA << " et " << _nationB << '\n';
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
        cout << " - Ce modèle n'existe pas." << endl;
        return;
    }

    if (_parcours == "DFS") {
        cout << "Existe-t-il une route entre les planètes " << _depart << " et " << _arrivee << " pour un vaisseau de type " << _modele << "?" << endl;
        res = v->getSysteme().DFS(_depart, _arrivee);
    }
    else if (_parcours == "Dijkstra-distance") {
        cout << "Existe-t-il une route la plus courte entre les planètes " << _depart << " et " << _arrivee << " pour un vaisseau de type " << _modele << "?" << endl;
        res = v->getSysteme().dijkstra(_depart, _arrivee, "distance");
    }
    else if (_parcours == "Dijkstra-cout") {
        cout << "Existe-t-il une route la moins dispendieux entre les planètes " << _depart << " et " << _arrivee << " pour un vaisseau de type " << _modele << "?" << endl;
        res = v->getSysteme().dijkstra(_depart, _arrivee, "cout");
    }
    else {
        cout << " - Ce parcours n'existe pas" << endl;
        return;
    }

    if (res.estVide()) {
        cout << " - Aucune route n'existe entre les planètes " << _depart << " et " << _arrivee << ", pour le modèle : " << _modele << endl;
        return;
    }

    cout << " - Il existe une route entre les planètes " << _depart << " et " << _arrivee <<  ", pour le modèle : " << _modele << '\n';
    cout << " - " << res.toString() << endl;
    if (_parcours == "Dijkstra-distance") {
        cout << " - La distance à parcourir est de : " << res.distance() << '\n';
    }
    else if (_parcours == "Dijkstra-cout") {
        cout << " - Le cout total est de           : " << res.cout() << '\n';
    }
    cout << "\n\n";
}

/**
* Fonction permettant l'affichage de tous les éléments en mémoire.
*/
void Jeu::afficherTout() {
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
}