#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "Graphe.h"
#include "InfoLog.h"
#include <map>

// struct Cle1
// {
//     string source;
//     string destinataire;
//     Cle1(string src = "", string dest = "") : source(src), destinataire(dest)
//     {}
// };

// typedef map<Cle1, int> Tgraph;
// Tgraph parcours;

// struct Renseignements
// {
//     string IP;
//     string date;
//     string heure;
//     string destinataire;
//     string typeDoc;
//     string status;
//     string qteData;
//     string referer;
//     string clientNav;
//     Renseignements(string ip = "", string dt = "", string h = "", string dest ="",
//     string td = "", string st = "", string qd = "", string ref = "",
//     string cN = "") : 
//     IP(ip), date(dt), heure(h), destinataire(dest), typeDoc(td), status(st), 
//     qteData(qd), referer(ref), clientNav(cN)
//     {}
// };

// inline bool operator< (const Cle1 & uneCle, const Cle1 & uneAutre)
// {
//     return uneCle.source.compare(uneAutre.source);
// }


// void Ajouter(const Renseignements & log)
// {
//     Cle1 infos;
//     infos.source = log.referer;
//     infos.destinataire = log.destinataire;

//     if(parcours.find(infos) != parcours.end() && !parcours.empty())
//     {
//         parcours.insert(pair <Cle1, int> (infos, parcours.find(infos)->second++));
//     }else{
//         parcours.insert(pair <Cle1, int> (infos, 1));
//     }
// }

// ostream & operator<<(ostream & os, Tgraph & g)
// {
//     os << g.begin()->first.destinataire << "    " << g.begin()->first.source << g.begin()->second << endl;
//     return os;
// }

int main ()
{
    //Cle1 *uneCle = new Cle1("source", "desti");
    //cout << uneCle->source;
    
    Renseignements info = Renseignements("test1", "ds", "sd", "intranet", "gq", "gqggg", "reeeeeeeey", "google.com", "zry");
    InfoLog *log1 = new InfoLog(info);

    Renseignements info2 = Renseignements("test1", "ds", "sd", "intranet", "gq", "gqggg", "reeeeeeeey", "google.com", "zry");
    InfoLog *log2 = new InfoLog(info2);

    Renseignements info3 = Renseignements("test1", "ds", "sd", "google.com", "gq", "gqggg", "reeeeeeeey", "mozilla", "zry");
    InfoLog *log3 = new InfoLog(info3);

    Graphe *ungraphe = new Graphe();
    ungraphe->Ajouter(*log1);
    ungraphe->Ajouter(*log2);
    ungraphe->Ajouter(*log3);

    //ungraphe->Afficher();

    ungraphe->Generer("court.dot");

    //ungraphe->LectureFichier("fichierInput.txt");
    ungraphe->Generer("court.dot");
    // InfoLog test = InfoLog(info);

    return 0;
}