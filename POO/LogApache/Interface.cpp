/*************************************************************************
                           Interface  -  description
                             -------------------
    début                : 17/01/2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/
//----- Réalisation de la classe <Interface> (fichier Interface.cpp) -----

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "Graphe.h"

//------------------------------------------------------ Include personnel


//----------------------------------------------- Déclaration des méthodes

//------------------------------------------------ Définition des méthodes
int chercherOtions(vector<string> & args, string options);

int main(int argc, char * argv[])
{
    Graphe *ungraphe = new Graphe();
    // ne pas utiliser argv[0], c'est le nom de l'exécutable
    cout << "-> " << argv[0] << endl;

    vector<string> args(argv, argv+argc);
    string g = "-g"; 
    string e = "-e";
    string t = "-t";

    int gPresent = chercherOtions(args, g);
    int ePresent = chercherOtions(args, e);
    int tPresent = chercherOtions(args, t);

    if(argc == 2)
    {
        ungraphe->LectureFichier(args[argc-1], 0, 0, -1);
        ungraphe->FaireTop10();
        cout << "Top 10 : " << endl;
        ungraphe->AfficherTop10();
    }else if(tPresent != 0 && gPresent != 0 && ePresent != 0)
    {
        int heure = stoi(args[tPresent+1]);

        ungraphe->LectureFichier(args[argc-1], 1, 1, heure);
        ungraphe->Generer(args[gPresent+1]);
        cout << "Dot-file "<< args[gPresent+1] << " generated" << endl;
        cout << "Il ne contient pas les extensions css, image, javascript" << endl;
        cout << "WARNING : only hits between " << heure << " and " << heure+1 << " have been taken into account" << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }else if((gPresent != 0) && (ePresent != 0))
    {
        ungraphe->LectureFichier(args[argc-1], 1, 1, -1);
        ungraphe->Generer(args[gPresent+1]);
        cout << "Dot-file court.dot generated" << endl;
        cout << "Il ne contient pas les extensions css, image, javascript" << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }else if(tPresent != 0 && gPresent != 0)
    {
        int heure = stoi(args[tPresent+1]);

        ungraphe->LectureFichier(args[argc-1], 1, 0, heure);
        ungraphe->Generer(args[gPresent+1]);
        cout << "Dot-file court.dot generated" << endl;
        cout << "Il ne contient pas les extensions css, image, javascript" << endl;
        cout << "WARNING : only hits between " << heure << " and " << heure+1 << " have been taken into account" << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }else if(gPresent != 0)
    {
        cout << "je passe par la" << endl;
        cout << args[argc-1] << endl;
        ungraphe->LectureFichier(args[argc-1], 1, 0, -1);
        //ungraphe->LectureFichier("fichierInput.txt", 1, 0, -1);
        ungraphe->Generer(args[gPresent+1]);
        cout << "Dot-file court.dot generated" << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }else if(ePresent != 0)
    {
        ungraphe->LectureFichier(args[argc-1], 0, 1, -1);
        cout << "Top 10 sans extensions : " << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }else if(tPresent != 0)
    {
        int heure = stoi(args[tPresent+1]);

        ungraphe->LectureFichier(args[argc-1], 0, 0, heure);
        cout << "Top 10 dans un créneau horaire : " << endl;
        ungraphe->FaireTop10();
        ungraphe->AfficherTop10();
    }
    else{
        cerr << "Options invalides" << endl;
        cerr << "Fermeture de l'application" << endl;
    }

    return 0;
}

int chercherOtions(vector<string> & args, string options)
{
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == options) {
            return i;
        }
    }
    return 0;
}