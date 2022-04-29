#pragma once
#include "planete.h"
constexpr auto OUT_OF_BOUND = numeric_limits<float>::max();

/**
* Classe représentant les arètes, les liens entre les différentes planètes.
* Chaque arète est composée des distances et cout afin d’aller de la planète source à la planète destination.
*/
class Arete
{
private:
	float distance;							// Distance entre deux planetes.
	float cout;								// Cout de déplacement entre deux planetes.
public:
	Planete* src;							// La source de l’arête, la planète de départ.
	Planete* dst;							// La destination de l’arête, la planète d’arrivée.
	Arete();								// Constructeur par défaut.
	Arete(Planete*, Planete*, const float);	// Constructeur de Arête.
	~Arete();								// Destructeur par défaut.
	float getDistance() const;				// Getter de Distance.
	float getCout() const;					// Getter de Cout.
	void initialiser(float const);			// Initialisation de l’Arete.
	float calculerDistance() const;			// Calcul de la distance entre src et dst.
	float calculerCout() const;				// Calcul du cout entre src et dst.
	void rendreAccessible();				// Rendre l’Arete accessible.
	void rendreInaccessible();				// Rendre l’Arete inaccessible.
};
