/*************************************************************************
                           Lecture  -  description
                             -------------------
    début                : Janvier 2022
    copyright            : VOTE Robin, GREL Hugo, 
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Lecture> (fichier Lecture.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <sstream>
#include <time.h>


//------------------------------------------------------ Include personnel
#include "Lecture.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Lecture::LireDonnees(map<string, Sensor> & listeCapteurs,list<Attribute> & listeAttributs, list<PrivateUser> & listePrivateUsers,
list<Cleaner> & listeCleaners, list<Provider> & listeProviders,
multimap<Sensor, Measurement> & mesuresO3, multimap<Sensor, Measurement> & mesuresSO2,
multimap<Sensor, Measurement> & mesuresNO2, multimap<Sensor, Measurement> & mesuresPM10)
{
    try
    {
        ifstream fic;
        string temp;
        stringstream scraping;
        struct tm tm = {0};
        const char * timeFormat = "%Y-%m-%d %H:%M:%S";

        //Stockage des sensors
        fic.open("dataset/sensors.csv");
        if(!fic.fail())
        {
            string id;
            double latitude;
            double longitude;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, id, ';');
                getline(scraping, temp, ';');
                latitude = stod(temp);
                getline(scraping, temp, ';');
                longitude = stod(temp);
                Sensor * s = new Sensor(id, latitude, longitude);
                listeCapteurs.insert(make_pair(id, *s));
            }
        }
        fic.close();
        
        //Stockage des attributs
        fic.open("dataset/attributes.csv");
        if(!fic.fail())
        {
            string id;
            string unit;
            string description;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, id, ';');
                getline(scraping, unit, ';');
                getline(scraping, description, ';');
                Attribute * a = new Attribute(id, unit, description);
                listeAttributs.push_back(*a);
            }
        }
        fic.close();

        //Stockage des cleaners
        fic.open("dataset/cleaners.csv");
        if(!fic.fail())
        {
            string id;
            double lat;
            double longi;
            time_t debut;
            time_t fin;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, id, ';');
                getline(scraping, temp, ';');
                lat = stod(temp);
                getline(scraping, temp, ';');
                longi = stod(temp);
                getline(scraping, temp, ';');
                strptime(temp.c_str(), timeFormat, &tm);
                debut = mktime(&tm);
                getline(scraping, temp, ';');
                strptime(temp.c_str(), timeFormat, &tm);
                fin = mktime(&tm);
                Cleaner * c = new Cleaner(id, lat, longi, debut, fin);
                listeCleaners.push_back(*c);
            }
        }
        fic.close();

        //Stockage des utilisateurs possédant des capteurs
        fic.open("dataset/users.csv");
        if(!fic.fail())
        {
            string userId;
            string sensorId;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, userId, ';');
                getline(scraping, sensorId, ';');
                PrivateUser * u = new PrivateUser(userId, "Jean", "Dupond", "jean.dupond@insa-lyon.fr", "123456", 0, sensorId);
                listePrivateUsers.push_back(*u);
            }
        }
        fic.close();

        //Stockage des providers
        fic.open("dataset/providers.csv");
        if(!fic.fail())
        {
            string providerId;
            string cleanerId;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, providerId, ';');
                getline(scraping, cleanerId, ';');
                Provider * p = new Provider(providerId, cleanerId);
                listeProviders.push_back(*p);
            }
        }
        fic.close();

        //Stockage des mesures
        fic.open("dataset/cleaners.csv");
        if(!fic.fail())
        {
            string sensorId;
            string attribute;
            double value;
            time_t timestamp;
            while(getline(fic, temp, '\n'))
            {
                scraping << temp;
                getline(scraping, temp, ';');
                strptime(temp.c_str(), timeFormat, &tm);
                timestamp = mktime(&tm);
                getline(scraping, sensorId, ';');
                getline(scraping, attribute, ';');
                getline(scraping, temp, ';');
                value = stod(temp);
                Measurement * c = new Measurement(timestamp, value, attribute);

                map<string, Sensor>::iterator it;
                it = listeCapteurs.find(sensorId);

                if(!attribute.compare("O3"))
                {
                    mesuresO3.insert(make_pair(it->second, *c));
                }else if(!attribute.compare("SO2"))
                {
                    mesuresSO2.insert(make_pair(it->second, *c));
                }else if(!attribute.compare("NO2"))
                {
                    mesuresNO2.insert(make_pair(it->second, *c));
                }else if(!attribute.compare("PM10"))
                {
                    mesuresPM10.insert(make_pair(it->second, *c));
                }else
                {
                    throw std::invalid_argument("type ne correspond a aucun type existant");
                }
            }
        }
        fic.close();

    }catch(exception& e)
    {
        cerr << "ERREUR : Mise en forme du fichier non valide";
        return 0;
    }
    return 1;
}


//-------------------------------------------- Constructeurs - destructeur
Lecture::Lecture ( const Lecture & unLectureLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Lecture>" << endl;
#endif
} //----- Fin de Lecture (constructeur de copie)


Lecture::Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Lecture>" << endl;
#endif
} //----- Fin de Lecture


Lecture::~Lecture ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Lecture>" << endl;
#endif
} //----- Fin de ~Lecture


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

