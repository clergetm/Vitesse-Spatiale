#include "arete.h"

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
*/
Arete::Arete() {
	this->src = this->dst = nullptr;
	rendreInaccessible();
}

/**
* Constructeur de Arete.
* @param	_src :		la planete source.
* @param	_dst :		la planete destination.
* @param	_limite :	la capacité en carburant du vaisseau, soit sa limite de déplacement.
*/
Arete::Arete(Planete* _src, Planete* _dst, const float _limite) {
	this->src = _src;
	this->dst = _dst;
	initialiser(_limite);
}

/**
* Destructeur par défaut.
*/
Arete::~Arete() {}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter de Distance.
* @return	la distance si l’arete peut être parcouru par le vaisseau. OUT_OF_BOND sinon.
*/
float Arete::getDistance() const { return distance; }

/**
* Getter de Cout.
* @return	le cout si l’arete peut être parcouru par le vaisseau. OUT_OF_BOND sinon.
*/
float Arete::getCout() const { return cout; }

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Initialiser les données de la structure.
* @param	_limite : la capacité en carburant du vaisseau, soit sa limite de déplacement.
*/
void Arete::initialiser(float const _limite) {
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
float Arete::calculerDistance() const {
	return (float)sqrt(pow(dst->getX() - src->getX(), 2) + pow(dst->getY() - src->getY(), 2));
};

/**
* Obtenir le cout de déplacement entre la Planete source et la Planete destination.
* @return	le cout en float.
*/
float Arete::calculerCout() const {
	return src->getPrixCarburant() * calculerDistance();
};

/**
* Rendre accessible le noeud.
* Il faut donc mettre à jour les informations.
*/
void Arete::rendreAccessible() {
	cout = calculerCout();
	distance = calculerDistance();
}

/**
* Rendre inaccessible le noeud.
*/
void Arete::rendreInaccessible() {
	cout = distance = OUT_OF_BOUND;
}