#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vaisseau
{
private:
	string modele;
	float capacite;
	

public:
	string getModele() const;
	float getCapacite() const;
	bool operator == (Vaisseau);





};

