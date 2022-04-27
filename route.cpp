#include "route.h"

//// CONSTRUCTEURS DESTRUCTEURS ///////////////////////////////////////////////////////////////////

/**
* Constructeur par défaut.
*/
Route::Route() {}

/**
* Destructeur par défaut.
*/
Route::~Route(){}

//// GETTERS SETTERS //////////////////////////////////////////////////////////////////////////////

/**
* Getter du point de départ.
* @return	La première planète de cette route.
*/
Planete* Route::depart() const { 
    if (!this->etapes.empty()) {
        return this->etapes.front().src;
    }
    else {
        return nullptr;
    }
}

/**
* Getter du point d’arrivée.
* @return	La dernière planète de cette route.
*/
Planete* Route::arrivee() const { 
    if (!this->etapes.empty()) {
        return this->etapes.back().dst;
    }
    else {
        return nullptr;
    }
}

bool Route::estVide() const
{
    return etapes.empty();
}

//// FONCTIONS ////////////////////////////////////////////////////////////////////////////////////

/**
* Calcul du cout de cette route.
* @param	_vaisseau : le vaisseau voulant emprunter la route.
* @return	le cout total du parcours de cette route, ou -1 si le vaisseau ne peut emprunter cette route.
*/
float Route::cout() const {
    float res = 0;
    for (auto it = etapes.cbegin(); it != etapes.cend(); ++it) {
        res += (*it).getCout();
    }
    return res;
}

/**
* Calcul de la distance parcourue avec cette route.
* @param	_vaisseau : le vaisseau voulant emprunter la route.
* @return	la distance totale du parcours de cette route, ou -1 si le vaisseau ne peut emprunter cette route.
*/
float Route::distance() const {
    float res = 0;
    for (auto it = etapes.cbegin(); it != etapes.cend(); ++it) {
        res += (*it).getDistance();
    }
    return res;
}

/**
* Modification d’une étape à un emplacement.
* @param	_index : l’emplacement auquel placer la planète.
* @param	_etape : une étape à ajouter à cette route.
*/
void Route::modifierEtape(const short _index, const Arete _etape){
	
    // On vérifie que ce ne soit pas le TOUT premier élément que l’on ajoute
    // Ou que l’on souhaite pas modifier un index négatif
    if (this->etapes.size() != 0 && _index > 0) {

        // On vérifie que l’index que l’on veut modifier est inférieur au nombre d’éléments
        if (_index < (short)this->etapes.size()) {
            this->etapes[_index] = _etape;
        }
        // Sinon on ajoute simplement à la fin
        else {
            this->etapes.push_back(_etape);
        }
    }

    // Sinon on ajoute simplement au début
    else {
        this->etapes.push_front(_etape);
    }
}

/**
* Insertion d’une étape à la fin.
* @param	_etape : une étape à ajouter à cette route.
*/
void Route::ajouterEtape(const Arete _etape) {
	this->etapes.push_back(_etape);
}

/**
* Représentation textuelle de la route.
* @return   un string avec le nom de toutes les planètes visitées.
*/
string Route::toString() const {
    string res ="";
    if (!etapes.empty()) {
        for (auto it = etapes.cbegin(); it != etapes.cend(); ++it) {
            res += (*it).src->getNomPlanete() + " >> ";
        }

        res += arrivee()->getNomPlanete();
    }
    return res;
}