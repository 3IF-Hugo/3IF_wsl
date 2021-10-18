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
 void Ensemble::tri(void){	
	//Algorithme : Tri à bulles
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
 }

 void Ensemble::Afficher(void)
 {
    this->tri();
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
    unsigned int nbPresent=0;
    if(unEnsemble.cardActuelle == cardActuelle )
    {
        for(unsigned int i=0; i<cardActuelle; i++)
        {
            for(unsigned int j=0; j<unEnsemble.cardActuelle;j++)
            {
                if(elements[i]==unEnsemble.elements[j])
                {
                    nbPresent++;
                    continue;
                }
            }
        }
        if(nbPresent == cardActuelle)
        {
            return true;
        }else return false;
    }else return false;
}

crduEstInclus Ensemble::EstInclus(const Ensemble & unEnsemble)const
{
    unsigned int nbPresent=0;
    if(this->EstEgal(unEnsemble))
    {
        return INCLUSION_LARGE;
    }
    else if(this->cardActuelle>unEnsemble.cardActuelle)
    {
        return NON_INCLUSION;
    }else{
        for(unsigned int i=0; i<cardActuelle; i++)
        {
            for(unsigned int j=0; j<unEnsemble.cardActuelle;j++)
            {
                if(elements[i]==unEnsemble.elements[j])
                {
                    nbPresent++;
                    continue;
                }
            }
        }
        if(nbPresent==cardActuelle)
        {
            return INCLUSION_STRICTE;
        }else return NON_INCLUSION;
    }
}

crduAjouter Ensemble::Ajouter(int aAjouter)
{
    for(unsigned int i=0; i<cardActuelle; i++)
    {
        if(elements[i] == aAjouter)
        {
            return DEJA_PRESENT;
            
        }
    }
    if(cardActuelle<cardMax)
    {
        elements[cardActuelle]=aAjouter;
        cardActuelle++;
        this->tri();
        return AJOUTE;
    }
    return PLEIN;
}

unsigned int Ensemble::Ajuster(int delta)
{
    if(delta>0)
    {
        int *new_elements = new int [cardMax+delta];
        for(unsigned int i =0;i<cardActuelle;i++){
            new_elements[i]=elements[i];
        }
        elements=new_elements;
        cardMax+=delta;
    }else if(delta<0)
    {
        int ecart = cardMax - cardActuelle;
        if((-delta)<=ecart)
        {
            int *new_elements = new int [cardMax+delta];
            for(unsigned int i =0;i<cardActuelle;i++){
                new_elements[i]=elements[i];
            }
            elements=new_elements;
            cardMax+=delta;
        }
        if((-delta)>ecart)
        {
            int *new_elements = new int [cardMax-ecart];
            for(unsigned int i =0;i<cardActuelle;i++){
                new_elements[i]=elements[i];
            }
            elements=new_elements;
            cardMax-=ecart;
        }
    }else if(delta == 0)
    {
        return cardMax;
    }
    return cardMax;
}

bool Ensemble::Retirer(int element)
{
    for(unsigned int i=0; i<cardActuelle; i++)
    {
        if(elements[i] == element)
        {
            int inter = elements[i];
            elements[i]=elements[cardActuelle];
            elements[cardActuelle]=inter;
            cardActuelle--;
            this->tri();
            this->Ajuster(-1);
            return true;
        }
    }
    this->Ajuster(-1);
    return false;



    /*
    bool estPresent = false;
    for(unsigned int i=0; i<cardActuelle; i++)
    {
        if(elements[i] == element)
        {
            estPresent = true;
        }
    }
    if(estPresent==false)
    {
        cardMax=cardActuelle;
        return false;
    }else{
        int *new_elements = new int [cardActuelle];
        for(unsigned int i=0; i<cardActuelle; i++)
        {
            if(elements[i]==element)
            {
                continue;
            }
            new_elements[i]=elements[i];
        }
        cardMax=cardActuelle;
        return true;
    }*/
}

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
    for(unsigned int i=0; i<nbElements; i++)
    {
        bool trouve = false;
        for(unsigned int j=0; j<cardActuelle; j++)
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

