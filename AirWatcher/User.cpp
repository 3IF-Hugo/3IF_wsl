/*************************************************************************
                           User  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Réalisation de la classe <User> (fichier User.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "User.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Algorithme :
//
//{
//} //----- Fin de Méthode

string User::getUserId()
{
    return userId;
}

string User::getName()
{
    return name;
}

string User::getSurname()
{
    return surname;
}

string User::getMail()
{
    return email;
}

string User::getPassword()
{
    return password;
}

//------------------------------------------------- Surcharge d'opérateurs
User & User::operator = ( const User & unUser )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
User::User ( const User & unUser )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <User>" << endl;
#endif
} //----- Fin de User (constructeur de copie)


User::User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <User>" << endl;
#endif
} //----- Fin de User


User::~User ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <User>" << endl;
#endif
} //----- Fin de ~User


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

