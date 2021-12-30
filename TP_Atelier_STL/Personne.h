#pragma once
#include <iostream>
#include <string>
using namespace std;

class Personne
{
private:
	string nom;
	string adresse;
	string tele;
public:
	Personne(string n, string a, string t);
	void afficher() const;

};

