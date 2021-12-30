#include "Personne.h"

Personne::Personne(string n, string a, string t)
{
	this->nom = n;
	this->adresse = a;
	this->tele = t;
}



void Personne::afficher() const
{
	cout << "nom: " << nom << " adresse: " << adresse << " tele: " << tele << endl;
}


