/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Sensor> (fichier Sensor.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Sensor::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool Sensor::SetStateUnreliable(){
    this->state = Unreliable;
    return true;
}

string Sensor::getSensorID() const{
    return sensorID;
}

double Sensor::getLatitude(){
    return latitude;
}

double Sensor::getLongitude(){
    return longitude;
}

StateSensorUser Sensor::getState(){
    return state;
}

//------------------------------------------------- Surcharge d'opérateurs
Sensor & Sensor::operator= ( const Sensor & unSensor )
// Algorithme :
//
{
    return *this; 
} //----- Fin de operator =

bool operator< ( const Sensor & sensor1, const Sensor & sensor2)
{
    return (sensor1.sensorID < sensor2.sensorID);
}

bool operator== ( Sensor & sensor1, const Sensor & sensor2)
{
    return (sensor1.sensorID == sensor2.sensorID);
}


//-------------------------------------------- Constructeurs - destructeur
Sensor::Sensor ( const Sensor & unSensor )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Sensor>" << endl;
#endif

    sensorID = unSensor.sensorID;
    latitude = unSensor.latitude;
    longitude = unSensor.longitude;
    state = unSensor.state;
} //----- Fin de Sensor (constructeur de copie)


Sensor::Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif
} //----- Fin de Sensor

Sensor::Sensor(string id, double lat, double log):
sensorID(id),latitude(lat),longitude(log),state(Reliable)
{
#ifdef MAP
    cout << "Appel au constructeur de <Sensor>" << endl;
#endif

}

Sensor::~Sensor ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Sensor>" << endl;
#endif
} //----- Fin de ~Sensor


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

