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
    //Méthode qui affiche les caractéritiques du trajet

    virtual void Sauvegarder();
    //Méthode qui écrit les informations du trajet
    
    virtual bool EstCompose();
    //Méthode qui renvoie true si le trajet est composé, false sinon

    char* getVilleDepart();
    //Méthode qui renvoie la ville de départ.

    char* getVilleArrivee();
    //Méthode qui renvoie la ville d'arrivée

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );

    Trajet ( const char* villeDep, const char* villeArr );
    // Mode d'emploi :
    //          @param1 const char* : ville de départ
    //          @param2 const char* : ville d'arrivée

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

