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
#include <fstream>
//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "InfoLog.h"
#include "LectureLog.h"
//----------------------------------------------------------------- PUBLIC
const char SEP = '|';
//----------------------------------------------------- Méthodes publiques
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
            //On ne garde que l'heure au lieu de heure + minute + secondes
            logX.infos.heure.erase(2, 6);
            //On supprime le lien du referer s'il correspond au serveur local
            if(logX.infos.referer.find(nomDomaine) != string::npos)
            {
                logX.infos.referer.erase(0, nomDomaineSize);
            }

            //Aucune option renseignée, on ne fait que le top 10
            if(optG == 0 && optE == 0 && Theure == -1)
            {
                AjouterClassement(logX);
            }else if(optG == 1 && optE == 1 && Theure != -1) //Toute les options sont renseignées
            {
                if(!(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd")
                && stoi(logX.infos.heure) >= Theure && stoi(logX.infos.heure) < Theure+1)
                {
                    Ajouter(logX);
                    AjouterClassement(logX);
                }
            }else if(optG == 1 && optE == 1) // Les options -g et -e sont renseignées
            {
                if(!(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd"))
                {
                    Ajouter(logX);
                    AjouterClassement(logX);
                }
            }else if(optG == 1 && Theure  != -1) // Les options -g et -t sont renseignées
            {
                if(stoi(logX.infos.heure) < Theure && stoi(logX.infos.heure) > Theure+1)
                {
                    continue;
                }else{
                    Ajouter(logX);
                    AjouterClassement(logX);
                }
            }else if(optG == 1) //  Seule l'option -g est renseignée
            {
                Ajouter(logX);
                AjouterClassement(logX);
            }else if(optE == 1 && Theure != -1) // Les options -e et -t sont renseignées
            {
                if(!(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd")
                && stoi(logX.infos.heure) >= Theure && stoi(logX.infos.heure) < Theure+1)
                {
                    AjouterClassement(logX);
                }
            }else if(optE == 1) // Seule l'option -e est renseignée
            {
                if(!(logX.infos.typeDoc == "css" || logX.infos.typeDoc == "js" 
                || logX.infos.typeDoc == "jpg" || logX.infos.typeDoc == "gif"
                || logX.infos.typeDoc == "ico" || logX.infos.typeDoc == "jpeg"
                || logX.infos.typeDoc == "png" || logX.infos.typeDoc == "psd"))
                {
                    AjouterClassement(logX);
                }
            }else if(Theure != -1) // Seule l'option -t est renseignée
            {
                if(stoi(logX.infos.heure) >= Theure && stoi(logX.infos.heure) < Theure+1)
                {
                    AjouterClassement(logX);
                }
            }
        }
    }
}

void Graphe::Ajouter(const InfoLog & log)
{
    Cle infos = make_pair(log.infos.referer, log.infos.destinataire);

    if(parcours.count(infos) == 1)
    {
        parcours.insert(pair <Cle, int> (infos, ++parcours.find(infos)->second));
    }else{
        parcours.insert(pair <Cle, int> (infos, 1));
    }
}

void Graphe::AjouterClassement(const InfoLog & log)
{
    if(classement.count(log.infos.destinataire) == 1)
    {
        classement.insert(pair <string, int> (log.infos.destinataire, ++classement.find(log.infos.destinataire)->second));
    }else{
        classement.insert(pair <string, int> (log.infos.destinataire, 1));
    }
}

void Graphe::FaireTop10()
{
    Classement::const_iterator debut;
    Classement::const_iterator fin;
    debut = classement.begin();
    fin = classement.end();

    while(debut != fin)
    {
        top10.insert(pair <int, string> (debut->second, debut->first));
        debut++;
    }
}

void Graphe::AfficherTop10()
{
    Top10::const_reverse_iterator debut;
    Top10::const_reverse_iterator fin;

    debut = top10.rbegin();
    fin = top10.rend();
    int nbIteration = 0;

    while(nbIteration < 10 && debut != fin)
    {
        cout << debut->second << " (" << debut->first << " hits)" << endl;
        ++debut;
        ++nbIteration;
    }
}

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
Graphe::Graphe ( const Graphe & unGraphe )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LectureLog>" << endl;
#endif
} //----- Fin de Graphe (constructeur de copie)

Graphe::Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LectureLog>" << endl;
#endif
} // Constructeur par défaut

Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LectureLog>" << endl;
#endif
} //----- Fin de ~Graphe

