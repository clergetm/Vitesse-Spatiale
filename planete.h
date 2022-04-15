#pragma once
#include <string>
#include <iostream>
using namespace std;


class Planete
{
private:
	string nomPlanete;
	float x;
	float y;
	int population;
	string nation;
	float prixCarburant;

public:
	Planete(string, float, float, int, string, float);
	~Planete();

	string getNomPlanete() const;
	float getX() const;
	float getY() const;
	int getPopulation() const;
	string getNation() const;
	float getPrixCarburant() const;

	bool operator == (Planete _planete);




};

