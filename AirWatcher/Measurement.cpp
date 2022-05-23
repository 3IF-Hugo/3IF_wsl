/*************************************************************************
                           Measurement  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Measurement> (fichier Measurement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Measurement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Measurement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

time_t Measurement::getTimestamp(){
    return timestamp;
}

double Measurement::getValue(){
    return value;
}

Attribute Measurement::getAttribute()
{
    return attribute;
}


//------------------------------------------------- Surcharge d'opérateurs
Measurement & Measurement::operator = ( const Measurement & unMeasurement )
// Algorithme :
//
{
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Measurement::Measurement ( const Measurement & unMeasurement )
// Algorithme :
//
{
    timestamp = unMeasurement.timestamp;
    value = unMeasurement.value;
    attribute = unMeasurement.attribute;
#ifdef MAP
    cout << "Appel au constructeur de copie de <Measurement>" << endl;
#endif

    timestamp = unMeasurement.timestamp;
    value = unMeasurement.value;
} //----- Fin de Measurement (constructeur de copie)


Measurement::Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
} //----- Fin de Measurement

Measurement::Measurement(time_t ts, double val, Attribute attr):timestamp(ts),value(val),attribute(attr)
{
#ifdef MAP
    cout << "Appel au constructeur de <Measurement>" << endl;
#endif
}

Measurement::~Measurement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Measurement>" << endl;
#endif
} //----- Fin de ~Measurement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

