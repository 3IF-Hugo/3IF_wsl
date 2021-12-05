/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/
//----- Réalisation de la classe <Interface> (fichier Interface.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
#include "TrajetCompose.h"

//----------------------------------------------- Déclaration des méthodes

void Ajouter_trajet_simple(Catalogue *catalogueInput);

TrajetCompose* Ajouter_trajet_compose(Catalogue *catalogueInput);

void Ajouter_sous_trajet_simple(Catalogue *catalogueInput, TrajetCompose* unTrajet, char* villeDepart, char* villememoire);
//void Ajouter_sous_trajet_simple(Catalogue *catalogueInput, TrajetCompose *unTrajet);

void Rechercher_trajet(Catalogue *catalogueRecherche);

void Rechercher_trajet_avance(Catalogue *catalogueRecherche);

//------------------------------------------------ Définition des méthodes
int main()
{
    Catalogue *notreCatalogue = new Catalogue();
    int debut;
    while(1)
	{
        cout << "menu:" << endl;
        cout << "\t1: Ajouter un trajet simple" << endl;
        cout << "\t2: Ajouter un trajet composé" << endl;
        cout << "\t3: Rechercher un trajet" << endl;
        cout << "\t4: Recherche avancée d'un trajet" << endl;
        cout << "\t5: Afficher" << endl;
        cout << "\t0: quitter" << endl;
		
        int choix;
        cin >> choix;
		
        switch(choix)
		{
			case 0:
				goto fin;
			case 1:
				Ajouter_trajet_simple(notreCatalogue);
				break;
			case 2: 
            {
                TrajetCompose *nouveauTrajet = Ajouter_trajet_compose(notreCatalogue);
                debut = 1;
                char* villeCourante = new char [100];
                while(1)
                {
                    cout << "menu trajet composé:" << endl;
                    cout << "\t1: Ajouter une étape" << endl;
                    cout << "\t0: Finaliser le trajet composé" << endl;
                    
                    int choixSousMenu;
                    cin >> choixSousMenu;
                    
                    switch(choixSousMenu)
                    {
                        case 0:
                            goto finSousMenu;
                        case 1:
                            if(debut == 1)
                            {
                                Ajouter_sous_trajet_simple(notreCatalogue, nouveauTrajet, nouveauTrajet->getVilleDepart(), villeCourante);
                                debut = 0;
                            }else{
                                Ajouter_sous_trajet_simple(notreCatalogue, nouveauTrajet, villeCourante, villeCourante);
                            }
                            break;
                        default:
                            cout << "choix incorrect" << endl;
                    }
                }
                finSousMenu:
                delete[] villeCourante;
				break;
            }
			case 3:
				Rechercher_trajet(notreCatalogue);
				break;
            case 4:
                Rechercher_trajet_avance(notreCatalogue);
                break;
            case 5: 
				notreCatalogue->Afficher();
				break;
			default:
                cout << "choix incorrect" << endl;
				continue ; // revenir au menu
		}
	}
	fin:
    cout << "Au revoir" << endl;
    delete notreCatalogue;
    return 0;
}

void Ajouter_trajet_simple(Catalogue *catalogueInput)
/* Méthode pour ajouter un trajet simple à partir du clavier :
        @param Catalogue* : le catalogue dans lequel on veut ajouter ce trajet
        @read1 char* : ville de départ
        @read2 char* : ville d'arrivée
        @read3 char* : moyen de transport
        @call AjouterTrajetSimple : méthode de <Catalogue> 
*/
{
    char *lecture = new char[100];

    cout << "Ville de départ : ";
    cin >> lecture;
    //char* villeDepart = new char [sizeof(lecture)+1];
    char villeDepart[sizeof(lecture)+1];
    strcpy(villeDepart, lecture);

    cout << "Ville d'arrivée : ";
    cin >> lecture;
    //char* villeArr = new char [sizeof(lecture)+1];
    char villeArr[sizeof(lecture)+1];
    strcpy(villeArr, lecture);

    cout << "Moyen de transport : ";
    cin >> lecture;
    //char* moyenTransport = new char [sizeof(lecture)+1];
    char moyenTransport[sizeof(lecture)+1];
    strcpy(moyenTransport, lecture);

    catalogueInput->AjouterTrajetSimple(villeDepart, villeArr, moyenTransport);
    
    delete[] lecture;
    // delete[] villeDepart;
    // delete[] villeArr;
    // delete[] moyenTransport;
}

TrajetCompose* Ajouter_trajet_compose(Catalogue *catalogueInput)
/* Méthode pour ajouter un trajet composé à partir du clavier :
        @param Catalogue* : le catalogue dans lequel on veut ajouter ce trajet
        @read1 char* : ville de départ globale
        @read2 char* : ville d'arrivée globale
        @call AjouterTrajetCompose : méthode de <Catalogue> 
        @return TrajetCompose* : le trajet composé que l'on vient d'ajouter dans le catalogue
*/
{
    char *lecture = new char[100];

    cout << "Ville de départ : ";
    cin >> lecture;
    //char* villeDepart = new char [sizeof(lecture)+1];
    char villeDepart[sizeof(lecture)+1];
    strcpy(villeDepart, lecture);

    cout << "Ville d'arrivée : ";
    cin >> lecture;
    //char* villeArr = new char [sizeof(lecture)+1];
    char villeArr[sizeof(lecture)+1];
    strcpy(villeArr, lecture);
    
    delete[] lecture;

    return catalogueInput->AjouterTrajetCompose(villeDepart, villeArr);
}

void Ajouter_sous_trajet_simple(Catalogue *catalogueInput, TrajetCompose* unTrajet, char* villeDepart, char* villememoire)
/* Méthode pour ajouter un trajet simple faisant parti d'un trajet composé à partir du clavier :
        @param1 Catalogue* : le catalogue dans lequel on veut ajouter ce trajet
        @param2 TrajetCompose* : le trajet composé dans lequel on veut ajouter une étape
        @param3 char* : la ville d'arrivée de l'étape d'avant pour devenir la ville de départ de l'étape en cours
        @param4 char* : ville dans laquelle on va stocker la ville d'arrivée de cette étape
        @read1 char* : ville d'arrivée
        @read2 char* : moyen de transport
        @call AjouterSousTrajetSimple : méthode de <Catalogue> 
*/
{
    char *lecture = new char[100];

    cout << "Ville de départ de l'étape: " << villeDepart << endl;

    cout << "Ville d'arrivée de l'étape: ";
    cin >> lecture;
    //char* villeArr = new char [sizeof(lecture)+1];
    char villeArr[sizeof(lecture)+1];
    strcpy(villeArr, lecture);

    cout << "Moyen de transport : ";
    cin >> lecture;
    //char* moyenTransport = new char [sizeof(lecture)+1];
    char moyenTransport[sizeof(lecture)+1];
    strcpy(moyenTransport, lecture);

    catalogueInput->AjouterSousTrajetSimple(villeDepart, villeArr, moyenTransport, unTrajet);

    delete[] lecture;
    for(long unsigned int i = 0; i < sizeof(villeArr)+1; i++)
    {
        villememoire[i] = villeArr[i];
    }
}


void Rechercher_trajet(Catalogue *catalogueRecherche)
/* Méthode pour rechercher un trajet à partir de la ville de départ et d'arrivée (Recherche simple)
        @param1 Catalogue* : le catalogue dans lequel on veut rechercher un trajet
        @read1 char* : ville de départ
        @read2 char* : ville d'arrivée
        @call Rechercher : méthode de <Catalogue>
*/
{
    char *lecture = new char[100];

    cout << "Veuillez saisir la ville de départ et d'arrivée :" <<endl;
    cout << "Ville de départ : ";
    cin >> lecture;
    //char* villeDepart = new char [sizeof(lecture)+1];
    char villeDepart[sizeof(lecture)+1];
    strcpy(villeDepart, lecture);

    cout << "Ville d'arrivée : ";
    cin >> lecture;
    //char* villeArr = new char [sizeof(lecture)+1];
    char villeArr[sizeof(lecture)+1];
    strcpy(villeArr, lecture);

    catalogueRecherche->Rechercher(villeDepart, villeArr);

    delete[] lecture;
}

void Rechercher_trajet_avance(Catalogue *catalogueRecherche)
/* Méthode pour rechercher un trajet à partir de la ville de départ et d'arrivée (Recherche avancée)
        @param1 Catalogue* : le catalogue dans lequel on veut rechercher un trajet
        @read1 char* : ville de départ
        @read2 char* : ville d'arrivée
        @call Rechercher : méthode de <Catalogue>
*/
{
    char *lecture = new char[100];

    cout << "Veuillez saisir la ville de départ et d'arrivée :" <<endl;
    cout << "Ville de départ : ";
    cin >> lecture;
    //char* villeDepart = new char [sizeof(lecture)+1];
    char villeDepart[sizeof(lecture)+1];
    strcpy(villeDepart, lecture);

    cout << "Ville d'arrivée : ";
    cin >> lecture;
    //char* villeArr = new char [sizeof(lecture)+1];
    char villeArr[sizeof(lecture)+1];
    strcpy(villeArr, lecture);

    catalogueRecherche->RechercheAvancee(villeDepart, villeArr);

    delete[] lecture;

}