/*************************************************************************
                           PrivateUser  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <PrivateUser> (fichier PrivateUser.h) ----------------
#if ! defined ( PrivateUser_H )
#define PrivateUser_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
enum StateSensorUser { Reliable, Unreliable };
//------------------------------------------------------------------------
// Rôle de la classe <PrivateUser>
//
//
//------------------------------------------------------------------------

class PrivateUser : public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
    int getScore();
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool setScorePlus1();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //get the state of the sensor
    StateSensorUser getStatut();
    
//------------------------------------------------- Surcharge d'opérateurs
    PrivateUser & operator = ( const PrivateUser & unPrivateUser );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    PrivateUser ( const PrivateUser & unPrivateUser );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    // PrivateUser ( );
    // // Mode d'emploi :
    // //
    // // Contrat :
    // //


    // PrivateUser(string userId, string name, string surname, string email,
    // string password, int score, StateSensorUser stateSensorUser = Reliable);

    PrivateUser(string userId = "", string name = "", string surname = "", string email = "", 
    string password = "", int score = 0, StateSensorUser stateSensorUser = Reliable) 
    : User(userId, name, surname, email, password), score(score), statut(stateSensorUser)  {}
    

    virtual ~PrivateUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
int score;
string SensorId;
StateSensorUser statut;
};

//-------------------------------- Autres définitions dépendantes de <PrivateUser>

#endif // PrivateUser_H

