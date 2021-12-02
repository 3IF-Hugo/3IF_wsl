/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( Trajet_H )
#define Trajet_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//      Classe mère de l'arbre d'héritage des trajets.
//      Elle permet d'afficher les composantes du trajet
//      Elle permet d'accéder aux attributs en cas de besoin
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher () const;

    char* getVilleDepart();
    //Méthode qui renvoie la ville de départ.

    char* getVilleArrivee();
    //Méthode qui renvoie la ville d'arrivée

//------------------------------------------------- Surcharge d'opérateurs
    /*
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Trajet ( const char* villeDep, const char* villeArr );
    // Mode d'emploi :
    //          @param1 const char* : ville de départ
    //          @param2 const char* : ville d'arrivée
    // Contrat :
    //

    Trajet ( );

    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
char *villeDepart;
char *villeArrivee;
};

#endif // Trajet_H

