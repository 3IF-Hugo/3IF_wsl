/*************************************************************************
                           GovernmentAgencyUser  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <GovernmentAgencyUser> (fichier GovernmentAgencyUser.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "GovernmentAgencyUser.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

 GovernmentAgencyUser::GovernmentAgencyUser(string userId, string name, string surname, string email, 
     string password) :User(userId, name, surname, email, password) {}


GovernmentAgencyUser::~GovernmentAgencyUser ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GovernmentAgencyUser>" << endl;
#endif
} //----- Fin de ~GovernmentAgencyUser


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

