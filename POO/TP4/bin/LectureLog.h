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
//----------------------------------------------------- Méthodes publiques
    static bool getNextLog(ifstream & fic, InfoLog & logLine);
    /* Méthode pour lire ligne par ligne le fichier en entrée suivant des caractéristiques
        @param1 ifstream : input stream du fichier dans lequel lire la ligne
        @param2 InfoLog& : L'instance de classe InfoLog passée par référence qui va contenir les infos de la ligne lue
        @return bool : Retourne 1 si on a pu lire correctement la ligne, 0 sinon
    */

//------------------------------------------------- Surcharge d'opérateurs
    LectureLog & operator = ( const LectureLog & unLectureLog );


//-------------------------------------------- Constructeurs - destructeur
    LectureLog ( const LectureLog & unLectureLog );

    LectureLog ( );

    virtual ~LectureLog ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <LectureLog>

#endif // LectureLog_H

