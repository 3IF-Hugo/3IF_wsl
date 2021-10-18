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

    for(int i=cardActuelle-1; i>0; i--)
    {
        for(int j=0; j<i; j++){
            if(elements[j+1] < elements[j])
            {
                int temp = elements[j+1];
                elements[j+1] = elements[j];
                elements[j] = temp;
            }
        }
    }

    unsigned int i=0;
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

bool Ensemble::EstEgal(const Ensemble & unEnsemble)const
{
    bool egaux = false;
    bool testPresent = false;
    if(unEnsemble.cardActuelle == cardActuelle )
    {
        for(int i=0; i<unEnsemble.cardActuelle; i++)
        {
            for(int j=0; j<cardActuelle;j++)
            {
                if(elements[j]==unEnsemble.elements[i])
                {
                    testPresent = true;
                }
            }
        }
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
    cardActuelle = 0;
    cardMax = nbElements;
    elements = new int[nbElements];
    for(int i=0; i<nbElements; i++)
    {
        bool trouve = false;
        for(int j=0; j<cardActuelle; j++)
        {
            if(elements[j] == valeur[i])
            {
                trouve = true;
                break;
            }
        }
        if(!trouve)
        {
            elements[cardActuelle] = valeur[i];
            cardActuelle++;
        }
    }
} //----- Fin de Ensemble

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

