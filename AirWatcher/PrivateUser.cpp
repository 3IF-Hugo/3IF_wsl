/*************************************************************************
                           PrivateUser  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <PrivateUser> (fichier PrivateUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "PrivateUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type PrivateUser::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

int PrivateUser::getScore(){
    return score;
}

bool PrivateUser::setScorePlus1(){
    score++;
    return true;
}

//------------------------------------------------- Surcharge d'opérateurs
// PrivateUser & PrivateUser::operator = ( const PrivateUser & unPrivateUser )
// // Algorithme :
// //
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
PrivateUser::PrivateUser ( const PrivateUser & unPrivateUser ) : User(unPrivateUser)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <PrivateUser>" << endl;
#endif
    score = unPrivateUser.score;
    statut = unPrivateUser.statut;
} //----- Fin de PrivateUser (constructeur de copie)


// PrivateUser::PrivateUser ( )
// // Algorithme :
// //
// {
// #ifdef MAP
//     cout << "Appel au constructeur de <PrivateUser>" << endl;
// #endif
// } //----- Fin de PrivateUser

PrivateUser::PrivateUser(string userId, string name, string surname, string email, 
    string password, int score, string userSensor, StateSensorUser stateSensorUser) 
    : User(userId, name, surname, email, password), score(score), SensorId(userSensor), statut(stateSensorUser)  {}

PrivateUser::~PrivateUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <PrivateUser>" << endl;
#endif
} //----- Fin de ~PrivateUser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

