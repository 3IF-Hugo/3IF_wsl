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
const char SEP = '|';
//----------------------------------------------------- Méthodes publiques

inline bool operator< (const Cle1 & uneCle, const Cle1 & uneAutre)
{
    return uneCle.source.compare(uneAutre.source);
}

inline bool operator==(const Cle1 & uneCle, const Cle1 & uneAutre)
{
    if(!uneCle.source.compare(uneAutre.source) && !uneCle.destinataire.compare(uneAutre.destinataire))
    {
        return 1;
    }
}

// ostream & operator<<(ostream & os, Tgraph::const_iterator & it)
// {
//     os << it->first.source << SEP;
//     os << it->first.destinataire << SEP;
//     os << it->second << endl;
//     return os;
// }

// ostream & operator<<(ofstream & os, const Cle1 & uneCle)
// {
//     os << uneCle.source << "_" << uneCle.destinataire;
//     return os;
// }

void Graphe::Ajouter(const InfoLog & log)
{
    Cle1 infos;
    infos.source = log.infos.referer;
    infos.destinataire = log.infos.destinataire;

    if(parcours.count(infos) == 1) // La comparaison ne marche pas encore !!!
    {
        parcours.insert(pair <Cle1, int> (infos, parcours.find(infos)->second++));
    }else{
        parcours.insert(pair <Cle1, int> (infos, 1));
    }
}

// void Graphe::Afficher(string nom, ostream & f) const
// {
//     Tgraph::const_iterator debut;
//     Tgraph::const_iterator fin;

//     if(nom.empty())
//     {
//         debut = parcours.begin();
//         fin = parcours.end();
//     }//else{
//     //     debut = parcours.lower_bound(nom);
//     //     fin = parcours.upper_bound(nom);
//     // }

//     while(debut != fin)
//     {
//         f << debut;
//         debut++;
//     }
// }

void Graphe::Generer(string nomFic)
{
    ofstream fic (nomFic);
    // Sauvegarde de l'ancien flux de sortie de cout et mise à jour
    streambuf *oldCoutBuffer = cout.rdbuf ( fic.rdbuf ( ) );
    
    Tgraph::const_iterator debut;
    Tgraph::const_iterator fin;

    debut = parcours.begin();
    fin = parcours.end();
    
    //Première partie du .dot
    while(debut != fin)
    {
        // Ne pas faire comme ça, faire avec node0
        fic << debut->first.source << " [label=\"" << debut->first.source << "\"];" << endl;
        fic << debut->first.destinataire << " [label=\"" << debut->first.destinataire << "\"];" << endl;
        ++debut;
    }

    debut = parcours.begin();
    fin = parcours.end();

    //Deuxième partie du .dot
    while(debut != fin)
    {
        fic << debut->first.source << " -> " << debut->first.destinataire << " [label=\"" << debut->second << "\"];" << endl;
        ++debut;
    }

    //Redirection de cout sur la sortie initiale sauvegardée
    cout.rdbuf (oldCoutBuffer);
    fic.close();
}

//-------------------------------------------- Constructeurs - destructeur
// Graphe::Graphe ( const Graphe & unGraphe )
//----- Fin de Graphe (constructeur de copie)

// Graphe::Graphe (string name = "", Renseignements r = Renseignements())
// Constructeur de Graphe

Graphe::Graphe ( )
{}
// Constructeur par défaut

// Graphe::~Graphe ( )
// Destructeur de Graphe

