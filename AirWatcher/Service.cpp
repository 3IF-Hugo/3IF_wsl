/*************************************************************************
                           Service  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <list>
#include <string>
#include <map>
#include <cmath>
#include <chrono>
#include <ctime>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Service.h"
#include "Measurement.h"
#include "Sensor.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


double** Service::calculerStatistiques(list<Sensor> sensors, multimap <Sensor, Measurement> tousMeasurements, list <string> listeTypesDonnees, double latitude, double longitude, double rayonZone, int nbrJours){

    double** returnArray;
    returnArray = (double**) malloc(sizeof(double)*listeTypesDonnees.size());
    for(int i=0; i<(int)(listeTypesDonnees.size()); ++i)
    {
        returnArray[i] = (double*) calloc(3, sizeof(double));
    }
    list<Sensor> listSensorsArea;
    int nbMeasurements;
    double distance;
    
    // Recuperer les capteurs dans la zone choisie
    for(list <Sensor>::iterator it = sensors.begin(); it != sensors.end(); it++){
        // Calcul de la distance simple en 2D, amelioration possible avec la formule de haversine
        distance = sqrt(pow(it->getLatitude() - latitude, 2) + pow(it->getLongitude() - longitude, 2)); 
        if (distance < rayonZone){
            listSensorsArea.push_back(*it);
        }
    }

    long long borneSup = static_cast<long long>(time(0)); //maintenant, en secondes
    long long borneInf = borneSup - nbrJours*24*3600;
    int iterateur = 0; // Variable pour remplacer l'index de l'element pointe par 'itl' - a la place de la fonction distance(listTypesDonnees, itl)

    // Calculer la moyenne, le min et max pour chaque type de donnees
    for(list <string>::iterator itl = listeTypesDonnees.begin(); itl != listeTypesDonnees.end(); itl++){
        for(auto itm = tousMeasurements.rbegin(); itm != tousMeasurements.rend(); itm++){
            
            // Moyenne (Calculer la somme et diviser a la fin de cette boucle)
            if (static_cast<long long>(itm->second.getTimestamp()) < borneSup && static_cast<long long>(itm->second.getTimestamp()) > borneInf && itl->compare(itm->second.getAttribute().getAttributeId()) == 0){
                //returnArray[distance(listTypesDonnees, itl)][0] += itm->second.value;
                returnArray[iterateur][0] += itm->second.getValue();
                
                // Max
                if (itm->second.getValue() > returnArray[iterateur][1])
                {
                    //returnArray[distance(listTypesDonnees, itl)][1] = itm->second.value;
                    returnArray[iterateur][1] = itm->second.getValue();
                }

                // Min
                if (itm->second.getValue() < returnArray[iterateur][2])
                {
                    //returnArray[distance(listTypesDonnees, itl)][2] = itm->second.value;
                    returnArray[iterateur][2] = itm->second.getValue();
                }
                nbMeasurements++;
            }
        }
        returnArray[iterateur][0] /= nbMeasurements;
        nbMeasurements = 0;
        iterateur++;
    }
    return returnArray;
}



//------------------------------------------------- Surcharge d'opérateurs
// & Service::operator = ( const Service & unService )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Service::Service ( const Service & unService )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Service>" << endl;
#endif
} //----- Fin de Service (constructeur de copie)


Service::Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
} //----- Fin de Service


Service::~Service ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

