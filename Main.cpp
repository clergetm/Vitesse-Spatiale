#include <iostream>
#include <string>
#include <vector>
#include "graphe.h"
#include "planete.h"
#include "route.h"
#include "vaisseau.h"
using namespace std;

/*
* Membre de l’équipe 5:
* Lilou		ALLAIN	ALLL26520207
* Mathys	CLERGET	CLEM14050107
* Guillaume URVOY	URVG07119904
*/

void encadrement(string _titre) { cout << "///// " + _titre + " /////" << endl; }

void print(string _ele) { cout << _ele << '\n'; }

void test_Planete() {
	encadrement("Test Planète");

	Planete p1("Delta_1", 589.0f, 596.0f, 297369, "Delta", 68.93f);
	Planete p2("Delta_2", 598.0f, 656.0f, 3671086, "Delta", 102.45f);

	print(" nom    : " + p1.getNomPlanete());
	print(" x      : " + to_string(p1.getX()));
	print(" y      : " + to_string(p1.getY()));
	print(" pop    : " + to_string(p1.getPopulation()));
	print(" nation : " + p1.getNation());
	print(" prix   : " + to_string(p1.getPrixCarburant()));
	print(" string : " + p1.toString());

	print("Test p1 == p2 : " + (p1 == p2));
	print("Test p1 == p1 : " + (p1 == p1));


	encadrement("FIN Planète");
}

void test_Vaisseau() {
	encadrement("Test Vaisseau");
	Vaisseau v1("SUPP-ID75-P", 75);
	Vaisseau v2("SUPP-ID100-WP", 100);

	print(" modele   : " + v1.getModele());
	print(" capacité : " + to_string(v1.getCapacite()));
	print(" string   : " + v1.toString());
	print("Test v1 == v2 : " + (v1 == v2));
	print("Test v1 == v1 : " + (v1 == v1));

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
	print("a1 : " + to_string(a1.getDistance()));
	print("   - " + to_string(a1.getCout()));
	a2.initialiser(v1.getCapacite());
	print("a2 : " + to_string(a2.getDistance()));
	print("   - " + to_string(a2.getCout()));
	a3.initialiser(v1.getCapacite());
	print("a3 : " + to_string(a3.getDistance()));
	print("   - " + to_string(a3.getCout()));
	a4.initialiser(v1.getCapacite());
	print("a4 : " + to_string(a4.getDistance()));
	print("   - " + to_string(a4.getCout()));
	a5.initialiser(v1.getCapacite());
	print("a5 : " + to_string(a5.getDistance()));
	print("   - " + to_string(a5.getCout()));
	a6.initialiser(v1.getCapacite());
	print("a6 : " + to_string(a6.getDistance()));
	print("   - " + to_string(a6.getCout()));

	Route r1;
	print("Ajout d’une étape a1");
	r1.ajouterEtape(a1);
	print("Ajout d’une étape a2"); 
	r1.ajouterEtape(a3);
	print("Modification d’une étape a2 -> a3");
	r1.modifierEtape(1,a5);

	print(" départ   : " + r1.depart()->getNomPlanete());
	print(" arrivée  : " + r1.arrivee()->getNomPlanete());
	print(" cout     : " + to_string(r1.cout()));
	print(" distance : " + to_string(r1.distance()));
	print(" toString : " + r1.toString());
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

	print("To String : ");
	print(g.toStringMatrice());


	print("Retrait de 0,1");
	g.retirerArete(0, 1);
	print("To String : ");
	print(g.toStringMatrice());

	print("Test getter");
	print("- Get : Delta_1 (devrait obtenir Delta_1)");
	short index = g.getPlaneteidx("Delta_1");
	if (index != -1) {
		print(" - " + planetes.at(index).getNomPlanete());
	}
	else {
		print(" - élément introuvable");
	}

	print("- Get : Delta_4 (devrait obtenir -1)");
	index = g.getPlaneteidx("Delta_4");
	if (index != -1) {
		print(" - " + planetes.at(index).getNomPlanete());
	}
	else {
		print(" - élément introuvable");
	}

	encadrement("FIN Graphe");
}

int main() {
	setlocale(LC_CTYPE, "fr_FR");
	test_Planete();
	test_Vaisseau();
	test_Route();
	test_Graphe();
	system("pause");
	return 0;
}