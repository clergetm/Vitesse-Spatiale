#include <iostream>
#include <string>
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

	Planete p1("planete1",0,0,50,"nation1",2.99);
	Planete p2("planete2",0,1,100,"nation2",10.99);

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
	Vaisseau v1("modele1", 99.90);
	Vaisseau v2("modele2", 55.50);

	cout << " modele   : " << v1.getModele() << '\n';
	cout << " capacité : " << v1.getCapacite() << '\n';
	cout << " string   : " << v1.toString() << '\n';
	cout << "Test v1 == v2 : " << (v1 == v2) << '\n';
	cout << "Test v1 == v1 : " << (v1 == v1) << '\n';

	encadrement("FIN Vaisseau");


}
void test_Route() {

}

int main() {
	setlocale(LC_CTYPE, "fr_FR");

	test_vaisseau();

	system("pause");
	return 0;
}