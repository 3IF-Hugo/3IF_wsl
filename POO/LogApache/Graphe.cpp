/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include <fstream>
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Graphe::Ajouter(const InfoLog & log)
{
    Cle1 infos;
    infos.source = log.infos.referer;
    infos.destinataire = log.infos.destinataire;

    if(parcours.find(infos) != parcours.end() && !parcours.empty())
    {
        parcours.insert(pair<Cle1, int> (infos, parcours.find(infos)->second++));
    }else{
        parcours.insert(pair<Cle1, int> (infos, 1));
    }
}

// void Graphe::Ajouter(string nomfic)
// {
//     ifstream file (nomfic.c_str());
//     Abonne a;

//     if(file)
//     {
//         while(file >> a)
//         {
//             Ajouter(a);
//         }else{
//             cerr << "Problème d'accés au fichier : " << nomfic << endl;
//         }
//     }
// }

//-------------------------------------------- Constructeurs - destructeur
// Graphe::Graphe ( const Graphe & unGraphe )
//----- Fin de Graphe (constructeur de copie)

// Graphe::Graphe (string name = "", Renseignements r = Renseignements())
// Constructeur de Graphe

// Graphe::Graphe ( )
// Constructeur par défaut

// Graphe::~Graphe ( )
// Destructeur de Graphe

