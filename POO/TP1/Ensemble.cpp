/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : 18/10/21
    copyright            : (C) $YEAR$ par Hugo G
    e-mail               : hugo.grel@insa-lyon.fr
*************************************************************************/

//------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ensemble.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Ensemble::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

 void Ensemble::Afficher(void)
 {
    unsigned int i=0;
    unsigned int t;
    int inversion,valint;

    do
    {
       inversion=0;
       for(t=0;t<cardMax-1;t++)
        {
          if (elements[t] > elements[t+1])
            {
            valint = elements[t];
            elements[t]=elements[t+1];
            elements[t+1]=valint;
            inversion=1;
            }
          }
       }
     while(inversion);

    cout << cardActuelle << "\r\n";
	cout << cardMax << "\r\n";
    if(cardActuelle == 0){
		cout << "{}\r\n";
	}else{
		cout << "{";
		for(i = 0; i < cardActuelle;i++){
			cout << elements[i];
			if(i < cardActuelle-1) cout << ",";
		}
		cout << "}\r\n";
	}
 }

//------------------------------------------------- Surcharge d'opérateurs
/*Ensemble & Ensemble::operator = ( const Ensemble & unEnsemble )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
/*
Ensemble::Ensemble ( const Ensemble & unEnsemble )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Ensemble>" << endl;
#endif
} //----- Fin de Ensemble (constructeur de copie)
*/
Ensemble::Ensemble ( unsigned int cardMax )
{
#ifdef MAP
    cout << "Appel au constructeur de <Ensemble>" << endl;
#endif

this->cardMax = cardMax;
cardActuelle = 0;
elements = new int [cardMax];

} //----- Fin de Ensemble

Ensemble::Ensemble ( int valeur[], unsigned int nbElements )
{
    #ifdef MAP
        cout << "Appel au constructeur de <Ensemble>" << endl;
    #endif

    cardMax = nbElements;
    unsigned int i,j;
    int res=0;
    unsigned int cpt=0;
    unsigned int cptBis=1;
    elements = new int[cardMax];
    elements[0] = valeur[0];
    for(i=1;i<nbElements+1;i++)
    {
        for(j=0;j<cptBis;j++)
        {
            if(valeur[i]==elements[j])
            {
                res++;
            }
        }
        if(res==0)
        {
            cpt++;
            elements[cpt] = valeur[i];
            cptBis++;
        }
        res = 0;
    }
    cardActuelle = cpt;
} //----- Fin de Ensemble*/

Ensemble::~Ensemble ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Ensemble>" << endl;
#endif
delete[] elements;
} //----- Fin de ~Ensemble


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

