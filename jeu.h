#pragma once
#include "graphe.h"
#include "liste.h"
#include "planete.h"
#include "vaisseau.h"
#include <string>
using namespace std;

class jeu
{
private:
	Graphe<Planete> systeme;		// Graphe représentant les relations entre les planètes.
	Liste<string> conflits;			// Liste chaînée des conflits entre nations de ce jeu.
	Liste<Vaisseau> vaisseaux;		// Liste des vaisseaux du jeu.
};

