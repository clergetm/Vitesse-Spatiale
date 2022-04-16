#include <iostream>
#include <string>
#include <vector>
#include "planete.h"
#include "vaisseau.h"
#include "route.h"
using namespace std;

/*
* Membre de l’équipe 5:
* Lilou		ALLAIN	ALLL26520207
* Mathys	CLERGET	CLEM14050107
* Guillaume URVOY	URVG07119904
*/

void encadrement(string _titre) { cout << "///// " + _titre + " /////" << endl; }

void test_planete() {
	encadrement("Test Planète");

	Planete p1("Delta_1", 589.0f, 596.0f, 297369, "Delta", 68.93f);
	Planete p2("Delta_2", 598.0f, 656.0f, 3671086, "Delta", 102.45f);

	cout << " nom    : " << p1.getNomPlanete() << '\n';
	cout << " x      : " << p1.getX() << '\n';
	cout << " y      : " << p1.getY() << '\n';
	cout << " pop    : " << p1.getPopulation() << '\n';
	cout << " nation : " << p1.getNation() << '\n';
	cout << " prix   : " << p1.getPrixCarburant() << '\n';
	cout << " string : " << p1.toString() << '\n';

	cout << "Test p1 == p2 : " << (p1 == p2) << '\n';
	cout << "Test p1 == p1 : " << (p1 == p1) << '\n';


	encadrement("FIN Planète");
}

void test_vaisseau() {
	encadrement("Test Vaisseau");
	Vaisseau v1("SUPP-ID75-P", 75);
	Vaisseau v2("SUPP-ID100-WP", 100);

	cout << " modele   : " << v1.getModele() << '\n';
	cout << " capacité : " << v1.getCapacite() << '\n';
	cout << " string   : " << v1.toString() << '\n';
	cout << "Test v1 == v2 : " << (v1 == v2) << '\n';
	cout << "Test v1 == v1 : " << (v1 == v1) << '\n';

	encadrement("FIN Vaisseau");
}

void test_Route() {
	encadrement("Test Route");
	
	Planete p1("Delta_1", 589.0f, 596.0f, 297369, "Delta", 68.93f);
	Planete p2("Delta_2", 598.0f, 656.0f, 3671086, "Delta", 102.45f);
	Planete p3("Delta_3", 645.0f, 870.0f, 3671086, "Delta", 66.75f);
	Vaisseau v1("SUPP-ID75-P", 75);
	Vaisseau v2("SUPP-ID100-WP", 100);

	Arete a1(&p1, &p2, v1.getCapacite());	// a1 : 1 - 2
	Arete a2(&p2,&p1,v1.getCapacite());		// a2 : 2 - 1
	Arete a3(&p1,&p3,v1.getCapacite());		// a3 : 1 - 3
	Arete a4(&p3,&p1,v1.getCapacite());		// a4 : 3 - 1
	Arete a5(&p2,&p3,v1.getCapacite());		// a5 : 2 - 3
	Arete a6(&p3,&p2,v1.getCapacite());		// a6 : 3 - 2


	encadrement("Initialisation");
	a1.initialiser(v1.getCapacite());
	cout << "a1 : " << to_string(a1.distance) << '\n';
	a2.initialiser(v1.getCapacite());
	cout << "a2 : " << to_string(a2.distance) << '\n';
	a3.initialiser(v1.getCapacite());
	cout << "a3 : " << to_string(a3.distance) << '\n';
	a4.initialiser(v1.getCapacite());
	cout << "a4 : " << to_string(a4.distance) << '\n';
	a5.initialiser(v1.getCapacite());
	cout << "a5 : " << to_string(a5.distance) << '\n';
	a6.initialiser(v1.getCapacite());
	cout << "a6 : " << to_string(a6.distance) << '\n';

	Route r1;
	cout << "Ajout d’une étape a1" << '\n';
	r1.ajouterEtape(a1);
	cout << "Ajout d’une étape a2" << '\n'; 
	r1.ajouterEtape(a3);
	cout << "Modification d’une étape a2 -> a3" << '\n';
	r1.modifierEtape(1,a5);

	cout << " départ   : " << r1.depart().getNomPlanete() << '\n';
	cout << " arrivée  : " << r1.arrivee().getNomPlanete() << '\n';
	cout << " cout     : " << to_string(r1.cout()) << '\n';
	cout << " distance : " << to_string(r1.distance()) << '\n';
	cout << " toString : " << r1.toString() << '\n';
	encadrement("FIN Route");

}

void test_Graphe() {
	encadrement("test Graphe");
	Vaisseau v1("SUPP-ID75-P", 75);
	Planete p1("Delta_1", 589.0f, 596.0f, 297369, "Delta", 68.93f);
	Planete p2("Delta_2", 598.0f, 656.0f, 3671086, "Delta", 102.45f);
	Planete p3("Delta_3", 645.0f, 870.0f, 3671086, "Delta", 66.75f);

	vector<Planete> planetes = { p1,p2,p3 };
	Graphe g(&planetes, v1.getCapacite());

	cout << "To String : " << '\n';
	cout << g.toStringMatrice() << '\n';


	cout << "Retrait de 0,1" << '\n';
	g.retirerArete(0, 1);
	cout << "To String : " << '\n';
	cout << g.toStringMatrice() << '\n';
	encadrement("FIN Graphe");
}

int main() {
	setlocale(LC_CTYPE, "fr_FR");
	test_Graphe();
	system("pause");
	return 0;
}