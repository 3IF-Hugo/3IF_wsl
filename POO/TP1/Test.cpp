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
    Ensemble *e3 = new Ensemble(valeur,5);
    Ensemble *e4 = new Ensemble(valeur,2);
    Ensemble *e5 = new Ensemble(valeur,2);
    //3->Afficher();
    //e4->Afficher();
    bool estEgal = e3->EstEgal(*e5);
    //cout << "est égal : " << estEgal <<"\r\n";

    Ensemble *e6 = new Ensemble(valeurBis,5);
    Ensemble *e7 = new Ensemble(valeurTer,3);
    cout << e6->EstInclus(*e7) << "\r\n";

    delete e1;
    delete e2;
    delete e3;
    delete e4;
    delete e5;
    

return 0;
} //----- fin de Nom

