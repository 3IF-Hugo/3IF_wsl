/*************************************************************************
                           GovernmentAgencyUser  -  description
                             -------------------
    début                : 02/05/22
    copyright            : B3324 et B3328
*************************************************************************/

//---------- Interface de la classe <GovernmentAgencyUser> (fichier GovernmentAgencyUser.h) ----------------
#if ! defined ( GOVERNMENTAGENCYUSER_H )
#define GOVERNMENTAGENCYUSER_H

//--------------------------------------------------- Interfaces utilisées
#include "User.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GovernmentAgencyUser>
//
//
//------------------------------------------------------------------------

class GovernmentAgencyUser: public User
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur

    GovernmentAgencyUser(string userId = "", string name = "", string surname = "", string email = "", string password = "");
    

    virtual ~GovernmentAgencyUser ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <GovernmentAgencyUser>

#endif // GovernmentAgencyUser_H

