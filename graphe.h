#pragma once
#include "liste.h"
using namespace std;

template<class T>
class graphe
{
private:
	bool** matriceAdj;
	short int nbElements;
	liste<T> elements;							// Liste chaînée des elements.
public:
	graphe(const short int);
	void initMatrice(const short int);
	~graphe();
	void ajouterArete(short int, short int);
	void retirerArete(short int, short int);
	void ajouterElement(T&);
	void retirerElement(T&);
};

