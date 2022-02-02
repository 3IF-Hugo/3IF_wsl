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
//------------------------------------------------------ Include personnel
#include "Application.h"
//----------------------------------------------- Déclaration des méthodes
int chercherOptions(vector<string> & args, string options);
//------------------------------------------------ Définition des méthodes
int main(int argc, char * argv[])
{
    Application* uneApplication = new Application();

    cout << "-> " << argv[0] << endl;

    vector<string> args(argv, argv+argc);
    string g = "-g"; 
    string e = "-e";
    string t = "-t";

    int gPresent = chercherOptions(args, g);
    int ePresent = chercherOptions(args, e);
    int tPresent = chercherOptions(args, t);

    try
    {
        if(gPresent != 0 && (gPresent < ePresent || gPresent < tPresent))
        {
            throw string("ERREUR : L'option -g doit être mise en dernier ! Relancer l'application...");
        }

        if(tPresent != -1)
        {
            int heure = stoi(args[tPresent+1]);
            if(0 > heure || heure > 24)
            {
                throw string("ERREUR : L'heure renseignée n'est pas conforme");
            }
        }
        if(argc == 2)
        {
            uneApplication->LectureFichier(args[argc-1], 0, 0, -1);
            uneApplication->FaireTop10();
            cout << "Top 10 : " << endl;
            uneApplication->AfficherTop10();
        }else if(tPresent != 0 && gPresent != 0 && ePresent != 0 && argc == 7)
        {
            int heure = stoi(args[tPresent+1]);

            uneApplication->LectureFichier(args[argc-1], 1, 1, heure);
            uneApplication->Generer(args[gPresent+1]);
            cout << "Dot-file "<< args[gPresent+1] << " generated" << endl;
            cout << "Il ne contient pas les extensions css, image, javascript" << endl;
            cout << "WARNING : only hits between " << heure << " and " << heure+1 << " have been taken into account" << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if((gPresent != 0) && (ePresent != 0) && argc == 5)
        {
            uneApplication->LectureFichier(args[argc-1], 1, 1, -1);
            uneApplication->Generer(args[gPresent+1]);
            cout << "Dot-file "<< args[gPresent+1] << " generated" << endl;
            cout << "Il ne contient pas les extensions css, image, javascript" << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if(tPresent != 0 && gPresent != 0 && argc == 6)
        {
            int heure = stoi(args[tPresent+1]);

            uneApplication->LectureFichier(args[argc-1], 1, 0, heure);
            uneApplication->Generer(args[gPresent+1]);
            cout << "Dot-file "<< args[gPresent+1] << " generated" << endl;
            cout << "Il ne contient pas les extensions css, image, javascript" << endl;
            cout << "WARNING : only hits between " << heure << " and " << heure+1 << " have been taken into account" << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if(gPresent != 0 && argc == 4)
        {
            cout << args[argc-1] << endl;
            uneApplication->LectureFichier(args[argc-1], 1, 0, -1);
            uneApplication->Generer(args[gPresent+1]);
            cout << "Dot-file "<< args[gPresent+1] << " generated" << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if(tPresent != 0 && ePresent != 0 && argc == 5)
        {
            int heure = stoi(args[tPresent+1]);
            uneApplication->LectureFichier(args[argc-1], 0, 1, heure);
            cout << "Top 10 dans un créneau horaire sans les extensions : " << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if(ePresent != 0 && argc == 3)
        {
            uneApplication->LectureFichier(args[argc-1], 0, 1, -1);
            cout << "Top 10 sans extensions : " << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }else if(tPresent != 0 && argc == 4)
        {
            int heure = stoi(args[tPresent+1]);

            uneApplication->LectureFichier(args[argc-1], 0, 0, heure);
            cout << "Top 10 dans un créneau horaire : " << endl;
            uneApplication->FaireTop10();
            uneApplication->AfficherTop10();
        }
        else{
            throw string("ERREUR : Options invalides ! Relancer l'application...");
        }
    }
    catch(string const& chaine)
    {
        cerr << chaine << endl;
    }

    delete uneApplication;
    
    return 0;
}

int chercherOptions(vector<string> & args, string options)
{
    for (size_t i = 1; i < args.size(); ++i) {
        if (args[i] == options) {
            return i;
        }
    }
    return 0;
}