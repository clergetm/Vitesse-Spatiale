#include <iostream>
#include <string>
#include "liste.h"
#include "graphe.h"
using namespace std;

/*
* Lilou		ALLAIN	ALLL26520207
* Mathys	CLERGET	CLEM14050107
* Guillaume URVOY	URVG07119904
*/

void test_Liste() {
	cout << "/////test_Liste///////////////////////" << '\n';
	Liste<int> l = Liste<int>(4);

	l.insererFin(1);
	l.insererFin(2);
	l.insererFin(3);
	l.insererFin(4);

	cout << "Affichage liste INT" << '\n';
	string res;
	for (l.fixerTete(); l.estDansListe(); l.suivant()) {
		int _temp = l.valeurCourante();
		res += to_string(_temp)+ '\n';
	}
	cout << res << '\n';

	cout << "Trouver" << '\n';
	cout << "Trouver 1 (doit être true)  : " << l.trouver(1) << '\n';
	cout << "  - Valeur Courante  : " << l.valeurCourante() << '\n';

	cout << "Trouver 5 (doit être false) : " << l.trouver(5) << '\n';
	cout << "  - Valeur Courante  : " << l.valeurCourante() << '\n';

	cout << "Longueur : " << to_string(l.longueur()) << '\n';
	cout << "Suppression" << '\n';
	cout << "- suppression 4 " << '\n';
	l.supprimer(4);
	cout << "- suppression 2" << '\n';
	l.supprimer(2);
	cout << "- suppression 5" << '\n';
	l.supprimer(5);

	cout << "Longueur : " << to_string(l.longueur()) << '\n';

	cout << "- Affichage liste INT" << '\n';
	res = "";
	for (l.fixerTete(); l.estDansListe(); l.suivant()) {
		int _temp = l.valeurCourante();
		res += " - "+to_string(_temp) + '\n';
	}
	cout << res << endl;

}

void test_Graphe() {
	cout << "/////test_Graphe//////////////////////" << '\n';
	Liste<int> l = Liste<int>(4);

	l.insererFin(1);
	l.insererFin(2);
	l.insererFin(3);
	l.insererFin(4);

	Graphe<int> g = Graphe<int>(&l);
	cout << "Insertion" << '\n';
	cout << " - insertion(0, 1)" << '\n';
	g.ajouterArete(0, 1);
	cout << " - insertion(0, 2)" << '\n';
	g.ajouterArete(0, 2);
	cout << " - insertion(1, 3)" << '\n';
	g.ajouterArete(1, 3);
	cout << " - insertion(2, 3)" << '\n';
	g.ajouterArete(2, 3);

	cout << "EstArete" << '\n';
	cout << " - (0,1) : " << g.estArete(0, 1) << '\n';
	cout << " - (1,2) : " << g.estArete(1, 2) << '\n';
	cout << " - (1,3) : " << g.estArete(1, 3) << '\n';
	cout << " - (1,4) : " << g.estArete(1, 4) << '\n';

	cout << "Affichage Matrice" << '\n';
	cout << g.toStringMatrice() << '\n';
}

int main() {
	setlocale(LC_CTYPE, "fr_FR");

	test_Graphe();

	system("pause");
	return 0;
}