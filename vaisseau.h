#pragma once
#include <string>
using namespace std;

class Vaisseau
{
private:
	string modele;					// Modèle du Vaisseau.
	float capacite;					// Capacité en carburant du Vaisseau.
public:
	Vaisseau(string, float);		// Constructeur par défaut.
	~Vaisseau();					// Destructeur par défaut.
	string getModele() const;		// Getter de modele. 
	float getCapacite() const;		// Getter de la capacite en carburant.
	string toString() const;		// Obtenir une représentation textuelle.
	bool operator == (Vaisseau);	// Surcharge de l'opérateur == pour les comparaisons.


			/*
				* Surcharge de l’opérateur <<. Retour du toString de Vaisseau.
				* @param _out :			le stream de output.
				* @param _vaisseau :	la vaisseau à représenter.
				* @returns				le stream à jour.
				*/

	friend ostream& operator<< (ostream& _out, Vaisseau& _vaisseau) {

		_out << (_vaisseau.getModele()) + " " + to_string(_vaisseau.getCapacite());
		return _out;
	}
};
