#pragma once
#include <string>
#include <iostream>
using namespace std;


class Planete
{
private:
	string nomPlanete;
	float coord[2];
	int population;
	string nation;
	float prixCarburant;

public:
	Planete();
	bool operator == (Planete _planete);




};

