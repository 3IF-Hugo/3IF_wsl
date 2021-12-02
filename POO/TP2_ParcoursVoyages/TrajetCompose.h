/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 15/11/2021
    copyright            : VOTE Robin et GREL Hugo
    e-mail               : robin.vote@insa-lyon.fr et hugo.grel@insa-lyon.fr
*************************************************************************/

//--- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ---
#if ! defined ( TrajetCompose_H )
#define TrajetCompose_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//      Classe fille de Trajet.
//      Permet de créer des trajets composés sous la forme d'un enchainement
//      de trajets simples.
//      Elle permet l'affichage des composantes d'un trajet composé sous la
//      forme de la ville de départ et d'arrivée globale puis la composition
//      des trajets simples.
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void ajouter (Trajet *unTrajet);
    // Mode d'emploi :
    //          @param Trajet* : un trajet

    void Afficher () const;

//------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose (const char *villeDep, const char *villeArr);
    // Mode d'emploi :
    //          @param1 const char* : ville de départ
    //          @param2 const char* : ville d'arrivée
    //          @using constructeur de <Trajet>

    TrajetCompose ( );

    virtual ~TrajetCompose ( );
    //Destructeur de <TrajetCompose>

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
LinkedList *list;
};

#endif // TrajetCompose_H

