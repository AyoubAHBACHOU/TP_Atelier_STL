// TP_Atelier_STL.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include "Personne.h"


using namespace std;

/*Exercice 1*/
    //qst1
template<class T>
void remplir_deque(deque<T>& deq, vector<T>& vect) {
    for (auto c : vect) {
        deq.push_back(c);
    }
}
template<class T>
void afficher_deque(deque<T> deq) {
    for (auto c : deq) {
        cout << c << "\t";
    }
    cout << endl;
}
template <class T>
void deque_to_list(deque<T>& deq, list<T>& list) {
    for (auto c : deq) {
        list.push_back(c);
    }
}
template <class T>
void afficher_list(list<T> list) {
    for (auto c : list) { cout << c << "\t"; }
    cout << endl;
}

template<class T>
void list_sorted(deque<T>& deq, list<T>& lst) {
    deque_to_list(deq, lst);
    lst.sort();
    afficher_list(lst);
}
/*-------------------------------------------------------*/
    //qst2
template<class T>
void afficher_stack(stack<T> S) {
    if (!S.empty()) {
        cout << S.top() << "\t";
        S.pop();
    }
}

template <class T>
stack<T>& inverser_stack(stack<T> S)
{
    stack<T>* R = new stack<T>();
    while (!S.empty())
    {
        R->push(S.top());
        S.pop();
    }
    return *R;
}

template <class T>
stack<T>& inverser_stack_ref(stack<T>& S)
{
    stack<T>* R = new stack<T>();
    while (!S.empty())
    {
        R->push(S.top());
        S.pop();
    }
    return *R;
}

void nettoyer_blanc(stack<char>& s)
{
    stack<char> r;
    while (!s.empty())
    {
        char c = s.top();
        if (!isspace(c) && !ispunct(c))
            r.push(c);
        s.pop();
    }
    s = inverser_stack_ref(r);
}

void plindrome()
{
    stack<char> s;
    char t;
    do {
        t = getchar();
        if (t == '\n')
            break;
        s.push(t);
    } while (true);
    afficher_stack(s);
    stack<char>& r = inverser_stack(s);
    nettoyer_blanc(s);
    nettoyer_blanc(r);

    if (s == r)
    {
        cout << "la phrase est un plindrome" << endl;
    }
    else {
        cout << "la phrase n'est pas un plindrome" << endl;
    }

}
/*-------------------------------------------------------*/
    //qst3
void priority()
{
    string s;
    priority_queue<string> pq;
    cout << "taper _fin_ pour arreter la saisie" << endl;
    do
    {
        cin >> s;
        if (s == "fin") break;
        pq.push(s);
    } while (true);

    while (!pq.empty())
    {
        cout << " " << pq.top();
        pq.pop();
    }
}
/*-------------------------------------------------------*/
//exercice 2

auto lamb = [](string s) {
    int n = s.length();
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
        char k = s[i];
        if (k == 'a' || k == 'o' || k == 'e' || k == 'i' || k == 'y' || k == 'u')
        {
            k = '*';
        }
        tmp += k;
    }
    return tmp;
};
auto lamb2 = [](string s) {
    string tmp(s);
    transform(s.begin(), s.end(), tmp.begin(), toupper);
    return tmp;
};

vector<string>  inserer_chaine() {
    vector<string> lst;
    string tmp = "";
    cout << "entrez une chaine\n";
    cout << "Taper _fin_ si vous voullez terminer\n";
    while (true) {
        cin >> tmp;
        if (tmp == "fin") break;
        lst.push_back(tmp);
    }

    return lst;
}


void transf1()
{
    vector<string> lst = inserer_chaine();
    vector<string> tr(lst.size());
    transform(lst.begin(), lst.end(), tr.begin(), lamb);
    cout << "************\n";
    for (int i = 0; i < tr.size(); i++)
    {
        cout << tr.at(i) << "\t";
    }
}

void transf2()
{
    vector<string> lst = inserer_chaine();
    vector<string> tr(lst.size());
    transform(lst.begin(), lst.end(), tr.begin(), lamb2);
    cout << "************\n";
    for (int i = 0; i < tr.size(); i++)
    {
        cout << tr.at(i) << "\t";
    }
}
/*-------------------------------------------------------*/
//exercice 3
void map_personne() {
    unordered_map<string, Personne*> um;
    priority_queue<string, vector<string>, greater<string>> pq;
    Personne* p1 = new Personne("ayoub", "IMM LES TROIS VILLAS BVD les FAR ", "0639362696");
    Personne* p2 = new Personne("ahmed", "IMM LES TROIS VILLAS BVD les FAR ", "0639562696");
    Personne* p3 = new Personne("ayoub", "IMM LES TROIS VILLAS BVD les FAR ", "0639362696");
    um.insert(make_pair("b", p1));
    um.insert(make_pair("a", p2));
    um.insert(make_pair("c", p3));
    um.insert(make_pair("z", p1));
    for (auto it : um)
    {
        pq.push(it.first);
    }

    while (!pq.empty())
    {
        auto it = um.find(pq.top());
        it->second->afficher();
        pq.pop();
    }

}









int main()
{
    //exercice 1 
        //   qst1

            /*vector<string> vect = {"hi,","have","a","nice","day"};
            deque<string> deq;
            list<string> lst;
            remplir_deque(deq, vect);
            //afficher_deque(deq);
            list_sorted(deq, lst);*/

            // qst2 et 3
                //plindrome();
                //priority();
        /*---------------------------------------------*/

        //exercice 2
                //transf1();
                //transf2();
        /*---------------------------------------------*/

        //exercice 3
            //map_personne();

}


// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
