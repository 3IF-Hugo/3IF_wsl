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
            elements[i]=elements[cardActuelle-1];
            elements[cardActuelle-1]=inter;
            cardActuelle--;
            this->tri();
            this->Ajuster(-cardMax);
            return true;
        }
    }
    this->Ajuster(-cardMax);
    return false;
}

unsigned int Ensemble::Retirer (const Ensemble & unEnsemble)
{
    int cpt=0;
    unsigned int localCardMax = cardMax;
    unsigned int localCardActUnElem = unEnsemble.cardActuelle;
    unsigned int taille = unEnsemble.cardActuelle;
    int *valUnElem = new int [taille];

    for(unsigned int i=0;i<localCardActUnElem;i++)
    {
        valUnElem[i]= unEnsemble.elements[i];
    }

    for(unsigned int j=0;j < localCardActUnElem;j++)
    {
        if(Retirer(valUnElem[j]))
        {
            cpt++;
        }
    }
    cardMax=localCardMax;
    return cpt;
}

int Ensemble::Reunir(const Ensemble & unEnsemble)
{
    int count = 0;
	bool reajust = false;
	for(int i = 0 ; i < unEnsemble.cardActuelle;i++)
    {
		int a = Ajouter(unEnsemble.elements[i]);
		if(a == 1)
        {
			reajust = true;
			cardMax++;
			count++;
			Ajouter(unEnsemble.elements[i]);
		}
		else if(a == 2){
			count++;
		}
	
	}
	
	if(reajust)
        count = -count;
	return count;
}

unsigned int Ensemble::Intersection(const Ensemble & unEnsemble)
{
    unsigned int cpt =0;
    unsigned int stockCardAct = cardActuelle;
    int copieTab[cardActuelle];
    for(int i=0; i<cardActuelle; i++)
    {
        copieTab[i]=elements[i];
    }

    //Cas simple : intersection avec ensemble vide
    if(unEnsemble.cardActuelle==0)
    {
        for(int i=0; i<stockCardAct; i++)
        {
            Retirer(copieTab[i]);
            cpt++;
        }
        Ajuster(-cardMax);
        return cpt;
    }

    Ensemble *tmp = new Ensemble(1);
    tmp->cardActuelle = 1;
    for(unsigned int i=0; i<stockCardAct; i++)
    {
        tmp->elements[0]=copieTab[i];
        bool inclus = tmp->EstInclus(unEnsemble);
        if(inclus == 0)
        {
            Retirer(copieTab[i]);
            cpt++;
        }
    }
    Ajuster(-cardMax);
    return cpt;
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

