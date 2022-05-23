/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Lecture> (fichier Lecture.h) ----------------
#if ! defined ( LECTURE_H )
#define LECTURE_H


//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <fstream>
#include <cstring>
#include <map>
#include <list>

#include "Measurement.h"
#include "Sensor.h"
#include "Attribute.h"
#include "Cleaner.h"
#include "PrivateUser.h"
#include "Provider.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <Lecture>
//
//
//------------------------------------------------------------------------

class Lecture
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    static bool LireDonnees(map<string, Sensor> & listeCapteurs,list<Attribute> & listeAttributs, list<PrivateUser> & listePrivateUsers,
    list<Cleaner> & listeCleaners, list<Provider> & listeProviders,
    multimap<Sensor, Measurement> & mesuresO3, multimap<Sensor, Measurement> & mesuresSO2,
    multimap<Sensor, Measurement> & mesuresNO2, multimap<Sensor, Measurement> & mesuresPM10);
    /* Méthode pour lire ligne par ligne le fichier en entrée suivant des caractéristiques
        @param1 ifstream : input stream du fichier dans lequel lire la ligne
        @param2 InfoLog& : L'instance de classe InfoLog passée par référence qui va contenir les infos de la ligne lue
        @return bool : Retourne 1 si on a pu lire correctement la ligne, 0 sinon
    */

//------------------------------------------------- Surcharge d'opérateurs
    Lecture & operator = ( const Lecture & unLectureLog );


//-------------------------------------------- Constructeurs - destructeur
    Lecture ( const Lecture & unLectureLog );

    Lecture ( );

    virtual ~Lecture ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


};

//-------------------------------- Autres définitions dépendantes de <Lecture>

#endif // Lecture_H

