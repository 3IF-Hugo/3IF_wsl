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
#include <cstring>

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
// Algorithme :
//          Demande ou non à l'utilisateur des critères de sélection de sauvegarde en fonction du mode et appelle la méthode sauvegarder de LinkedList
{
    char * lecture = new char[100];
    char * villeDep;
    char * villeArr;
    int indiceDeb = 0;
    int indiceFin = 0;
    if(mode==3 || mode == 5)
    {
        cout << "Entrez le ville de départ : " << endl;
        cin >> lecture;
        villeDep = new char[sizeof(lecture)+1];
        strcpy(villeDep, lecture);
    }
    if(mode == 4 || mode == 5)
    {
        cout << "Entrez le ville d'arrivée : " << endl;
        cin >> lecture;
        villeArr = new char[sizeof(lecture)+1];
        strcpy(villeArr, lecture);
    }
    delete[] lecture;
    if(mode == 6)
    {
        cout << "Entrez le numéro du premier trajet (inclu) que vous voulez sauvegarder : " << endl;
        cin >> indiceDeb;
        cout << "Entrez le numéro du dernier trajet (inclu) que vous voulez sauvegarder : " << endl;
        cin >> indiceFin;
    }
    catalogueTrajet->Sauvegarder(mode, nomDuFichier, villeDep, villeArr, indiceDeb, indiceFin);
    if(mode == 3 || mode == 5)
    {
        delete[] villeDep;
    }
    if(mode == 4 || mode == 5)
    {
        delete[] villeArr;
    }
}

void Catalogue::GetTrajetSimple(ifstream &fic, string str, Catalogue *catalogueInput)
// Algorithme :
//              Lecture systématique des lignes pour créer un trajet simple
{
    string tmp[3];
    for(int i = 0; i < 3; ++i)
    // ville de départ
    // ville d'arrivée
    // moyen de transport
    {
        getline(fic,str,'\n');
        tmp[i] = str;
    }
    catalogueInput->AjouterTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str());
    getline(fic,str,'\n');  // _s
}

void Catalogue::GetTrajetSimpleCondition(ifstream &fic, string str, Catalogue *catalogueInput, char * ville1, char * ville2, int choix1,  int choix2)
// Algorithme :
//              Lecture systématique des lignes pour créer un trajet simple et ajout si condition satisfaite
{
    string tmp[3];
    for(int i = 0; i < 3; ++i)
    // ville de départ
    // ville d'arrivée
    // moyen de transport
    {
        getline(fic,str,'\n');
        tmp[i] = str;
    }
    if(strcmp(tmp[choix1].c_str(), ville1) == 0 && strcmp(tmp[choix2].c_str(), ville2) == 0)
    {
        catalogueInput->AjouterTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str());
    }
    getline(fic,str,'\n');  //_s
}

void Catalogue::GetTrajetCompose(ifstream &fic, string str, Catalogue *catalogueInput)
// Algorithme :
//              Lecture systématique des lignes pour créer un trajet composé
{
    string tmp[3];
    for(int i = 0; i < 2; ++i)
    // ville de départ
    // ville d'arrivée
    {
        getline(fic,str,'\n');
        tmp[i] = str;
    }
    TrajetCompose* newTrajetC = catalogueInput->AjouterTrajetCompose(tmp[0].c_str(), tmp[1].c_str());
    
    getline(fic,str,'\n'); // s
    do
    {
        for(int i = 0; i < 3; ++i)
        // ville de départ
        // ville d'arrivée
        // moyen de transport
        {
            getline(fic,str,'\n');
            tmp[i] = str;
        }
        catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
        getline(fic,str,'\n'); // _s
        getline(fic,str,'\n'); // s ou _c
    }while(str == "s");
}

void Catalogue::GetTrajetComposeCondition(ifstream &fic, string str, Catalogue *catalogueInput, char * ville1, char * ville2, int choix1,  int choix2)
// Algorithme :
//              Lecture systématique des lignes pour créer un trajet composé et ajout si condition satisfaite
{
    string tmp[3];
    for(int i = 0; i < 2; ++i)
    // ville de départ
    // ville d'arrivée
    {
        getline(fic,str,'\n');
        tmp[i] = str;
    }
    if(strcmp(tmp[choix1].c_str(), ville1) == 0 && strcmp(tmp[choix2].c_str(), ville2) == 0)
    {
        TrajetCompose* newTrajetC = catalogueInput->AjouterTrajetCompose(tmp[0].c_str(), tmp[1].c_str());
        getline(fic,str,'\n'); // s
        do
        {
            for(int i = 0; i < 3; ++i)
            // ville de départ
            // ville d'arrivée
            // moyen de transport
            {
                getline(fic,str,'\n');
                tmp[i] = str;
            }
            catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
            getline(fic,str,'\n'); // _s
            getline(fic,str,'\n'); // s ou _c
        }while(str == "s");
    }else{
        while(str != "_c")
        {
            getline(fic,str,'\n');
        }
    }
}

void Catalogue::ChargerMode1(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée tous les trajets du fichier texte
//              Si on récupére un "s", on crée un trajet simple sinon un trajet composé
{
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            getline(fic,str,'\n');  // type de trajet
            str.c_str();
            if(str == "s")
            {
                GetTrajetSimple(fic, str, catalogueInput);
            }else if(str == "c")
            {
                GetTrajetCompose(fic, str, catalogueInput);
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    else {
        cerr << "Erreur d’ouverture du fichier" << endl;
    }
    fic.close();
}

void Catalogue::ChargerMode2(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée tous les trajets suivant le type choisi par l'utilisateur
{
    cout << "Selon quel type de trajet souhaitez-vous sélectionner" << endl;
    cout << "Trajet simple : tapez 1" << endl;
    cout << "Trajet composé : tapez 2" << endl;
    int typeTrajet;
    cin >> typeTrajet;
    ifstream fic;
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            getline(fic,str,'\n');  // type de trajet
            str.c_str();
            if(typeTrajet == 1)
            {
                if(str == "s")
                {
                    GetTrajetSimple(fic, str, catalogueInput);
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
                    GetTrajetCompose(fic, str, catalogueInput);
                }else {
                    while(str != "_s")
                    {
                        getline(fic,str,'\n');
                    }
                }
            }
        }
    }
    fic.close();
}

void Catalogue::ChargerMode3(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée tous les trajets suivant la ville de départ sélectionnée
//              En récupérant la ville de départ de chacun des trajets du fichier texte, on la compare avec 
//              la ville sélectionnée, si c'est identique (attention à la casse), alors on charge le trajet
{
    char * lecture = new char[100];
    cout << "Entrez le ville de départ : " << endl;
    cin >> lecture;
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            getline(fic,str,'\n');  // type de trajet
            if(str == "s")
            {
                GetTrajetSimpleCondition(fic, str, catalogueInput, lecture, lecture, 0, 0);
            }else if(str == "c")
            {
                GetTrajetComposeCondition(fic, str, catalogueInput, lecture, lecture, 0, 0);
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    fic.close();
    delete[] lecture;
}

void Catalogue::ChargerMode4(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée tous les trajets suivant la ville d'arrivée sélectionnée
//              En récupérant la ville d'arrivée de chacun des trajets du fichier texte, on la compare avec 
//              la ville sélectionnée, si c'est identique (attention à la casse), alors on charge le trajet
{
    char * lecture = new char[100];
    cout << "Entrez la ville d'arrivée : " << endl;
    cin >> lecture;
    ifstream fic;
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            getline(fic,str,'\n');  // type de trajet
            if(str == "s")
            {
                GetTrajetSimpleCondition(fic, str, catalogueInput, lecture, lecture, 1, 1);
            }else if(str == "c")
            {
                GetTrajetComposeCondition(fic, str, catalogueInput, lecture, lecture, 1, 1);
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    fic.close();
    delete[] lecture;
}

void Catalogue::ChargerMode5(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée tous les trajets suivant la ville de départ et d'arrivée
//              sélectionnée.
//              En récupérant la ville de départ et d'arrivée de chacun des trajets du fichier texte, on les 
//              compare avec les villes sélectionnées, si c'est identique (attention à la casse), alors on charge
//              le trajet.
{
    char * lectureVilleDepart = new char[100];
    char * lectureVilleArr = new char[100];
    cout << "Entrez la ville de départ : " << endl;
    cin >> lectureVilleDepart;
    cout << "Entrez la ville d'arrivée : " << endl;
    cin >> lectureVilleArr;
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            getline(fic,str,'\n'); // type de trajet
            if(str == "s") // dans le cas d'un trajet simple
            {
                GetTrajetSimpleCondition(fic, str, catalogueInput, lectureVilleDepart, lectureVilleArr, 0, 1);
            }else if(str == "c")
            {
                GetTrajetComposeCondition(fic, str, catalogueInput, lectureVilleDepart, lectureVilleArr, 0, 1);
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    fic.close();
    delete[] lectureVilleDepart;
    delete[] lectureVilleArr;
}

void Catalogue::ChargerMode6(string nomDuFichier, Catalogue *catalogueInput)
// Algorithme :
//              Charge dans le catalogue en entrée les trajets suivant leur numéro
{
    char * indiceDeb = new char[100];
    char * indiceFin = new char[100];
    cout << "Entrez le numéro du premier trajet (inclu) que vous voulez charger : " << endl;
    cin >> indiceDeb;
    cout << "Entrez le numéro du dernier trajet (inclu) que vous voulez charger : " << endl;
    cin >> indiceFin;
    ifstream fic; // input stream
    fic.open (nomDuFichier);
    string str;
    string tmp[3]; 
    if(fic)
    {
        while(!fic.eof())
        {
            getline(fic,str,'\n');  // numéro
            string number = str;
            getline(fic,str,'\n'); // type de trajet
            if(str == "s")
            {
                for(int i = 0; i < 3; ++i)
                // ville de départ
                // ville d'arrivée
                // moyen de transport
                {
                    getline(fic,str,'\n');
                    tmp[i] = str;
                }
                if(indiceDeb <= number && number <= indiceFin)
                {
                    catalogueInput->AjouterTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str());
                }
                getline(fic,str,'\n');  // _s
            }else if(str == "c")
            {
                for(int i = 0; i < 2; ++i)
                // ville de départ
                // ville d'arrivée
                {
                    getline(fic,str,'\n');
                    tmp[i] = str;
                }
                if(indiceDeb <= number && number <= indiceFin)
                {
                    TrajetCompose* newTrajetC = catalogueInput->AjouterTrajetCompose(tmp[0].c_str(), tmp[1].c_str());
                    getline(fic,str,'\n'); // s
                    do
                    {
                        for(int i = 0; i < 3; ++i)
                        // ville de départ
                        // ville d'arrivée
                        // moyen de transport
                        {
                            getline(fic,str,'\n');
                            tmp[i] = str;
                        }
                        catalogueInput->AjouterSousTrajetSimple(tmp[0].c_str(), tmp[1].c_str(), tmp[2].c_str(),newTrajetC);
                        getline(fic,str,'\n'); // _s
                        getline(fic,str,'\n'); // s ou _c
                    }while(str == "s");
                }else{
                    while(str != "_c")
                    {
                        getline(fic,str,'\n');
                    }
                }
            }else {
                cout << "Erreur dans la mise en forme du fichier" << endl;
            }
        }
    }
    fic.close();
    delete[] indiceDeb;
    delete[] indiceFin;
}

void Catalogue::Charger(int mode, string nomDuFichier, Catalogue *catalogueInput)
{
    if(mode == 1)
    {
        ChargerMode1(nomDuFichier, catalogueInput);
    }else if(mode == 2)
    {
        ChargerMode2(nomDuFichier, catalogueInput);
    }else if(mode == 3)
    {
        ChargerMode3(nomDuFichier, catalogueInput);
    }else if(mode == 4)
    {
        ChargerMode4(nomDuFichier, catalogueInput);
    }else if(mode == 5)
    {
        ChargerMode5(nomDuFichier, catalogueInput);
    }else if(mode == 6)
    {
        ChargerMode6(nomDuFichier, catalogueInput);
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