/*************************************************************************
                           User  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <User> (fichier User.h) ----------------
#if ! defined ( User_H )
#define User_H

//--------------------------------------------------- Interfaces utilisées
using namespace std;
#include <string>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <User>
//
//
//------------------------------------------------------------------------

class User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    bool seConnecter(string mailIn, string mdpIn);
    // Mode d'emploi :
    //
    // Contrat :
    //

    bool seDeconnecter();

    bool inscrireUser(int idIn, string nomIn, string surnameIn, string mailIn, string mdpIn);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getUserId();

    string getName();

    string getSurname();

    string getMail();

    string getPassword();

//------------------------------------------------- Surcharge d'opérateurs
    User & operator = ( const User & unUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    User ( const User & unUser );
    //(constructeur de copie)

    User ( );
    // Constructeur par défaut

    User(string userId = "", string name = "", string surname = "", string email = "", string password = "") 
    : userId(userId), name(name), surname(surname), email(email), password(password) {}
    // Constructeur avec paramètres

    virtual ~User ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string userId;
string name;
string surname;
string email;
string password;
};

//-------------------------------- Autres définitions dépendantes de <User>

#endif // User_H

