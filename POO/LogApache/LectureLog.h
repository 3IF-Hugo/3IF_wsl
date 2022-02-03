/*************************************************************************
                           LectureLog  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <LectureLog> (fichier LectureLog.h) ----------------
#if ! defined ( LECTURELOG_H )
#define LECTURELOG_H


//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include "InfoLog.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <LectureLog>
//
//
//------------------------------------------------------------------------

class LectureLog
{
//----------------------------------------------------------------- PUBLIC

public:

    //friend class InfoLog;
//----------------------------------------------------- Méthodes publiques
    static bool getNextLog(ifstream & fic, InfoLog & logLine);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    LectureLog & operator = ( const LectureLog & unLectureLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & unLectureLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LectureLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~LectureLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // LectureLog_H

