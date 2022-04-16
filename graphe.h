#pragma once
#include <string>
#include <vector>
#include "planete.h"

constexpr short INIT = 100;
constexpr auto OUT_OF_BOUND = numeric_limits<float>::max();

/**
* Une arête contient un cout et une distance à parcourir pour aller de la source à la destination.
*/
struct Arete {
	Planete* src;		// La source de l’arête, la planète de départ.
	Planete* dst;		// La destination de l’arête, la planète d’arrivée.
	float distance;		// Distance entre deux planetes.
	float cout;			// Cout de déplacement entre deux planetes.

	Arete() {
		this->src = this->dst = nullptr;
		rendreInaccessible();
		
	}
	/**
	* Constructeur de Arete.
	* @param	_src : La planete source.
	* @param	_dst : La planete destination.
	* @param	_limite : la capacité en carburant du vaisseau, soit sa limite de déplacement.
	*/
	Arete(Planete* _src, Planete* _dst, const float _limite) {
		this->src = _src;
		this->dst = _dst;
		initialiser(_limite);
	}
	/**
	* Initialiser les données de la structure.
	* @param	_limite : la capacité en carburant du vaisseau, soit sa limite de déplacement.
	*/
	void initialiser(float const _limite) {
		// Si la distance est inférieur à la limite, c’est que le chemin est prenable par utilisable par le vaisseau.
		if (calculerDistance() < _limite) {
			rendreAccessible();
		}
		else {
			rendreInaccessible();
		}
	}
	
	/**
	* Calculer la distance séparant la Planete source de la destination.
	* @return	la distance en float.
	*/
	float calculerDistance() const {
		return (float)sqrt(pow(dst->getX() - src->getX(),2) + pow(dst->getY() - src->getY(),2));
	};
	
	/**
	* Obtenir le cout de déplacement entre la Planete source et la Planete destination.
	* @return	le cout en float.
	*/
	float calculerCout() const {
		return src->getPrixCarburant() * calculerDistance();
	};
	
	/**
	* Rendre accessible le noeud. 
	* Il faut donc mettre à jour les informations.
	*/
	void rendreAccessible() {
		cout = calculerCout();
		distance = calculerDistance();
	}
	
	/**
	* Rendre inaccessible le noeud.
	*/ 
	void rendreInaccessible() {
		cout = distance = OUT_OF_BOUND;
};
	};

class Graphe
{
private:
	Arete matrice[INIT][INIT];						// Matrice d’adjacence.
	short nbElements;								// Nombre d’élements 
	float limite;									// La capacité en carburant du vaisseau utilisant ce graphe. Symbolisant donc sa limite pour atteindre les planètes.
	vector<Planete>* planetes;						// Pointeur vers le vector des planètes.
public:
	Graphe(vector<Planete>*, const float);			// Constructeur de Graphe.
	~Graphe();										// Destructeur de Graphe.
	void ajouterArete(const short, const short);	// Ajouter une arète à la matrice.
	void retirerArete(const short, const short);	// Retirer une arète à la matrice.
	string toStringMatrice() const;					// Représentation textuelle de la Matrice.
};
