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
#include "InfoLog.h"
#include "LectureLog.h"
#include <fstream>
//----------------------------------------------------------------- PUBLIC
const char SEP = '|';
//----------------------------------------------------- Méthodes publiques

// inline bool operator< (const Cle1 & uneCle, const Cle1 & uneAutre)
// {
//     if(uneCle.source == uneAutre.source && uneCle.destinataire == uneAutre.destinataire)
//     {
//         return false;
//     }else{
//         return true;
//     }
//     //return uneCle.destinataire.compare(uneAutre.destinataire);
// }

// inline bool operator==(const Cle1 & uneCle, const Cle1 & uneAutre)
// {
//     if(!uneCle.source.compare(uneAutre.source) && !uneCle.destinataire.compare(uneAutre.destinataire))
//     {
//         return true;
//     }else{
//         return false;
//     }
// }

// ostream & operator<<(ostream & os, Tgraph::const_iterator & it)
// {
//     // Avec Cle1 struct :
//     // os << it->first.source << SEP;
//     // os << it->first.destinataire << SEP;
//     // os << it->second << endl;

//     // Avec Cle pair
//     os << it->first.first << SEP;
//     os << it->first.second << SEP;
//     os << it->second << endl;
//     return os;
// }

// ostream & operator<<(ofstream & os, const Cle1 & uneCle)
// {
//     os << uneCle.source << "_" << uneCle.destinataire;
//     return os;
// }

void Graphe::LectureFichier(string nomFic, int optG, int optE, int Theure)
{
    InfoLog logLine;
    ifstream fic;
    fic.open(nomFic);
    string nomDomaine = "http://intranet-if.insa-lyon.fr";
    int nomDomaineSize = nomDomaine.size();
    if(fic)
    {
        while(!fic.eof())
        {
            InfoLog & logX = LectureLog::getNextLog(fic, logLine);
            //-------- CAS OU IL N'Y A PAS DE REFERER ???? -----------//
            //-------- CAS DE LA TARGET BIZARRE AVEC temps/blabla/fichier.html;jsksfjqlksfj -----------//
            //On ne garde que l'heure au lieu de heure + minute + secondes
            logX.infos.heure.erase(2, 6);
            //On supprime le lien du referer s'il correspond au serveur local
            if(logX.infos.referer.find(nomDomaine) != string::npos)
            {
                logX.infos.referer.erase(0, nomDomaineSize);
            }

            if(optG == 1 && optE == 1 && Theure != -1)
            {
                if(!(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd")
                && stoi(logX.infos.heure) > Theure && stoi(logX.infos.heure) < Theure+1)
                {
                    cout << "je passe par là" << endl;
                    Ajouter(logX);
                }
            }else if(optG == 1 && optE == 1)
            {
                if(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd")
                {
                    continue;
                }else{
                    Ajouter(logX);
                }
            }else if(optG == 1 && Theure  != -1)
            {
                if(stoi(logX.infos.heure) < Theure && stoi(logX.infos.heure) > Theure+1)
                {
                    continue;
                }else{
                    Ajouter(logX);
                }
            }
        }
    }
}


void Graphe::Ajouter(const InfoLog & log)
{
    // Cle1 infos;
    // infos.source = log.infos.referer;
    // infos.destinataire = log.infos.destinataire;

    //Avec la pair :
    Cle infos = make_pair(log.infos.referer, log.infos.destinataire);

    if(parcours.count(infos) == 1)
    {
        parcours.insert(pair <Cle, int> (infos, ++parcours.find(infos)->second));
    }else{
        parcours.insert(pair <Cle, int> (infos, 1));
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
    typedef map<string, string> TypeNode;
    TypeNode node;
    int n = 0;

    string string_node = "node";
    string nodex;
    ofstream fic (nomFic);
    // Sauvegarde de l'ancien flux de sortie de cout et mise à jour
    streambuf *oldCoutBuffer = cout.rdbuf ( fic.rdbuf ( ) );

    // Entête du fichier 
    fic << "digraph { " << endl;
    
    Tgraph::const_iterator debut;
    Tgraph::const_iterator fin;

    debut = parcours.begin();
    fin = parcours.end();

    TypeNode::const_iterator debutNode;
    TypeNode::const_iterator finNode;

    debutNode = node.begin();
    finNode = node.end();
    
    //Première partie du .dot : On construit des nodes uniques, distintes les unes des autres
    while(debut != fin)
    {
        // Si on ne trouve pas la source dans la map temporaire, on l'ajoute
        if(node.count(debut->first.first) == 0)
        {
            nodex = string_node.append(to_string(n));
            node.insert(pair <string, string> (debut->first.first, nodex));
            ++n;
            string_node = "node";
        }

        // Si on ne trouve pas le destinataire dans la map temporaire, on l'ajoute
        if(node.count(debut->first.second) == 0)
        {
            nodex = string_node.append(to_string(n));
            node.insert(pair <string, string> (debut->first.second, nodex));
            ++n;
            string_node = "node";
        }
        
        // On construit le fichier .dot de sortie
        // On recherche dans la map temporaire la ville et on prend second, cad, le node avec numéro
        // fic << node.find(debut->first.first)->second << " [label=\"" << debut->first.first << "\"];" << endl;
        // fic << node.find(debut->first.second)->second << " [label=\"" << debut->first.second << "\"];" << endl;
        ++debut;
    }

    //On écrit sur le fichier de sortie la première partie concernant les nodes
    // On initialise
    debutNode = node.begin();
    finNode = node.end();

    // On parcourt la map du début à la fin
    while(debutNode != finNode)
    {
        fic << debutNode->second << " [label=\"" << debutNode->first << "\"];" << endl;
        ++debutNode;
    }

    //Deuxième partie du .dot
    // On ré-initialise les itérateurs
    debut = parcours.begin();
    fin = parcours.end();

    debutNode = node.begin();
    finNode = node.end();

    // On écrit dans le fichier, en s'aidant de la map temporaire, chaque trajet d'une node à l'autre
    while(debut != fin)
    {
        fic << node.find(debut->first.first)->second << " -> " << node.find(debut->first.second)->second << " [label=\"" << debut->second << "\"];" << endl;
        ++debut;
    }

    // Clôture du fichier 
    fic << "}" << endl;

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

