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
    e1->Afficher();
    e2->Afficher();

    int valeur[] = {0,8,4,-3,5,7,1};
    Ensemble *e3 = new Ensemble(valeur,5);
    Ensemble *e4 = new Ensemble(valeur,2);
    e3->Afficher();
    e4->Afficher();
    

return 0;
} //----- fin de Nom

