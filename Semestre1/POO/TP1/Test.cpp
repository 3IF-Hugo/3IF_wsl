/*************************************************************************
                           Test  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Test> (fichier Test.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
//------------------------------------------------------ Include personnel
#include "Test.h"
#include "Ensemble.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main ()
// Algorithme :
//
{
    Ensemble *e1 = new Ensemble(6);
    Ensemble *e2 = new Ensemble();
   // e1->Afficher();
    //e2->Afficher();

    int valeur[] = {0,8,4,4,-3,5,7,1};
    int valeurBis[] = {1,2,3,4,5};
    int valeurTer[] = {1,2,3};
    int valeur4[] = {4,4,4,4};
    Ensemble *e3 = new Ensemble(valeur,5);
    Ensemble *e4 = new Ensemble(valeur,2);
    Ensemble *e5 = new Ensemble(valeur,2);
    //e3->Afficher();
    //e4->Afficher();
    bool estEgal = e3->EstEgal(*e5);
    //cout << "est égal : " << estEgal <<"\r\n";

    Ensemble *e6 = new Ensemble(valeurBis,5);
    Ensemble *e7 = new Ensemble(valeurTer,3);
    Ensemble *e8 = new Ensemble(valeur4,4);
    //cout << e6->EstInclus(*e7) << "\r\n";
    //e4->Ajouter(4);
    //cout << e4->Ajouter(3) << "\r\n";
    //e3->Afficher();

    //cout << e7->Ajuster(2)<<"\r\n";
    /*
    e3->Afficher();
    e4->Afficher();
    cout << e3->Retirer(*e4)<<"\r\n";
    e3->Afficher();
    */
   /*
    e7->Afficher();
    cout<< e7->Reunir(*e3)<<"\r\n";
    e7->Afficher();*/

    e6->Afficher();
    e7->Afficher();
    cout<<e6->Intersection(*e7)<<"\r\n";
    e6->Afficher();

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    delete e6;
    delete e7;

return 0;
} //----- fin de Nom

