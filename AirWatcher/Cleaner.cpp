/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Cleaner> (fichier Cleaner.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Cleaner.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cleaner::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Cleaner::getCleanerId()
{
    return cleanerId;
}

double Cleaner::getLatitude()
{
    return latitude;
}

double Cleaner::getLongitude()
{
    return longitude;
}

time_t Cleaner::getTimestampStart()
{
    return timestampStart;
}

time_t Cleaner::getTimestampStop()
{
    return timestampStop;
}


//------------------------------------------------- Surcharge d'opérateurs
Cleaner & Cleaner::operator = ( const Cleaner & unCleaner )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Cleaner::Cleaner ( const Cleaner & unCleaner )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cleaner>" << endl;
#endif
    cleanerId = unCleaner.cleanerId;
    latitude = unCleaner.latitude;
    longitude = unCleaner.longitude;
    timestampStart = unCleaner.timestampStart;
    timestampStop = unCleaner.timestampStop;
} //----- Fin de Cleaner (constructeur de copie)

Cleaner::Cleaner (string cleanerId, double latitude, double longitude, time_t timestampStart, time_t timestampStop) 
: cleanerId(cleanerId), latitude(latitude), longitude(longitude), timestampStart(timestampStart), timestampStop(timestampStop)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cleaner>" << endl;
#endif
} //----- Fin de Cleaner


Cleaner::~Cleaner ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cleaner>" << endl;
#endif
} //----- Fin de ~Cleaner


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées