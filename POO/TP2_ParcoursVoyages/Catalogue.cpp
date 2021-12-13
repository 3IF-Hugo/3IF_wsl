/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//----- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::AjouterTrajetSimple ( const char* villeDepart, const char* villeArrivee, const char* moyenTransport )
// Algorithme :
//          Crée puis ajoute un nouveau trajet simple dans le catalogue de trajets
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    // nouveauTrajet->Afficher();
    catalogueTrajet->ajouter ( nouveauTrajet, 1);
} //----- Fin de Méthode

TrajetCompose* Catalogue::AjouterTrajetCompose ( const char* villeDepart, const char* villeArrivee )
// Algorithme :
//          Crée puis ajoute un nouveau trajet composé dans le catalogue de trajets.
//          Retourne le trajet créé. 
{
    TrajetCompose *nouveauTrajet = new TrajetCompose ( villeDepart, villeArrivee );
    catalogueTrajet->ajouter ( nouveauTrajet, 1 );
    return nouveauTrajet;
} //----- Fin de Méthode

void Catalogue::AjouterSousTrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport, TrajetCompose *unTrajetComp)
// Algorithme :
//          Crée puis ajoute un nouveau trajet simple dans le trajet composé correspondant.
{
    TrajetSimple *nouveauTrajet = new TrajetSimple ( villeDepart, villeArrivee, moyenTransport );
    unTrajetComp->ajouter(nouveauTrajet);
}

void Catalogue::Afficher()
{
    catalogueTrajet->afficher();
}

void Catalogue::Rechercher(const char* depart, const char* arrivee)
// Algorithme :
//          Crée un trajet avec les paramètres de recherche puis recherche ce trajet dans le catalogue
{
    Trajet *trajetRecherche = new Trajet(depart, arrivee);
    catalogueTrajet->Rechercher(trajetRecherche);
    delete trajetRecherche;
}

void Catalogue::RechercheAvancee(const char* depart, const char* arrivee)
// Algorithme :
//          Crée un trajet avec les paramètres de recherche puis recherche ce trajet dans le catalogue
{
    LinkedList * resultat = new LinkedList();
    if(catalogueTrajet->RechercheAvancee(depart, arrivee, 0, resultat))
    {
        resultat->afficher();
    }
    resultat->vider();
    delete resultat;
}

void Catalogue::Sauvegarder(int mode, string nomDuFichier)
{
    catalogueTrajet->Sauvegarder(mode, nomDuFichier);
}

void Catalogue::ChargerMode1(string nomDuFichier, Catalogue *catalogueInput)
{
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');
            string number = str;
            getline(fic,str,'\n');
            str.c_str();
            if(str == "s")
            {
                cout << "je passe par s"<<endl;
                for(int i = 0; i < 3; ++i)
                {
                    getline(fic,str,'\n');
                    tmp[i] = str;
                }
                catalogueInput->AjouterTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str());
                getline(fic,str,'\n');
            }else if(str == "c")
            {
                cout << "je passe par c"<<endl;
                for(int i = 0; i < 2; ++i)
                {
                    getline(fic,str,'\n');
                    tmp[i] = str;
                }
                TrajetCompose* newTrajetC = catalogueInput->AjouterTrajetCompose(tmp[0].c_str(), tmp[1].c_str());
                // getline(fic,str,'\n');
                // for(int i = 0; i < 3; ++i)
                // {
                //     getline(fic,str,'\n');
                //     tmp[i] = str;
                // }
                // catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                //getline(fic,str,'\n');
                getline(fic,str,'\n'); // s ?
                do
                {
                    for(int i = 0; i < 3; ++i)
                    {
                        getline(fic,str,'\n');
                        tmp[i] = str;
                    }
                    catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                    getline(fic,str,'\n'); // _s
                    getline(fic,str,'\n'); // s ?
                }while(str == "s");

                //getline(fic,str,'\n'); // _c
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    else {
        cerr << "Erreur d’ouverture de <test.txt>" << endl;
    }
    fic.close();

}

void Catalogue::ChargerMode2(string nomDuFichier, Catalogue *catalogueInput)
{
    cout << "Selon quel type de trajet souhaitez-vous sélectionner" << endl;
    cout << "Trajet simple : tapez 1" << endl;
    cout << "Trajet composé : tapez 2" << endl;
    int typeTrajet;
    cin >> typeTrajet;
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');
            string number = str;
            getline(fic,str,'\n');
            str.c_str();
            if(typeTrajet == 1)
            {
                if(str == "s")
                {
                    //cout << "je passe par s"<<endl;
                    for(int i = 0; i < 3; ++i)
                    {
                        getline(fic,str,'\n');
                        tmp[i] = str;
                    }
                    catalogueInput->AjouterTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str());
                    getline(fic,str,'\n');
                }else{
                    while(str != "_c")
                    {
                        getline(fic,str,'\n');
                    }
                }
            }else if(typeTrajet == 2)
            {
                if(str == "c")
                {
                    //cout << "je passe par c"<<endl;
                    for(int i = 0; i < 2; ++i)
                    {
                        getline(fic,str,'\n');
                        tmp[i] = str;
                    }
                    TrajetCompose* newTrajetC = catalogueInput->AjouterTrajetCompose(tmp[0].c_str(), tmp[1].c_str());
                    // getline(fic,str,'\n');
                    // for(int i = 0; i < 3; ++i)
                    // {
                    //     getline(fic,str,'\n');
                    //     tmp[i] = str;
                    // }
                    // catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                    // getline(fic,str,'\n'); //_s
                    // getline(fic,str,'\n'); // s ?
                    do
                    {
                        getline(fic,str,'\n'); // s ?
                        for(int i = 0; i < 3; ++i)
                        {
                            getline(fic,str,'\n');
                            tmp[i] = str;
                        }
                        catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                        getline(fic,str,'\n'); // _s
                        getline(fic,str,'\n'); // s ?
                    }while(str == "s");
                    getline(fic,str,'\n'); // _c
                    // if(str == "s")
                    // {
                    //     for(int i = 0; i < 3; ++i)
                    //     {
                    //         getline(fic,str,'\n');
                    //         tmp[i] = str;
                    //     }
                    //     catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                    //     getline(fic,str,'\n'); // _s
                    // }
                    // getline(fic,str,'\n'); // _c
                }else {
                    while(str != "_s")
                    {
                        getline(fic,str,'\n');
                    }
                }
            }
        }
    }
}

void Catalogue::Charger(int mode, string nomDuFichier, Catalogue *catalogueInput)
{
    if(mode == 1)
    {
        ChargerMode1(nomDuFichier, catalogueInput);
    }else if(mode == 2)
    {
        ChargerMode2(nomDuFichier, catalogueInput);
    }
}

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//      Initialise une LinkedList vide
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
catalogueTrajet = new LinkedList();
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
delete catalogueTrajet;
} //----- Fin de ~Catalogue

