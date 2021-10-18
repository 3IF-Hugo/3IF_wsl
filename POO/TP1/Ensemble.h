/*************************************************************************
                           Ensemble  -  description
                             -------------------
    début                : 18/10/21
    copyright            : (C) $YEAR$ par HugoG
    e-mail               : hugo.grel@insa-lyon.fr
*************************************************************************/

//--------Interface de la classe <Ensemble> (fichier Ensemble.h) ---------
#if ! defined ( Ensemble_H )
#define Ensemble_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes
const unsigned int CARD_MAX = 5;
//------------------------------------------------------------------ Types
enum crduEstInclus {NON_INCLUSION,INCLUSION_LARGE, INCLUSION_STRICTE};
enum crduAjouter{DEJA_PRESENT,PLEIN,AJOUTE};
//------------------------------------------------------------------------
// Rôle de la classe <Ensemble>
//
//
//------------------------------------------------------------------------

class Ensemble
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    Ensemble(unsigned int cardMax = CARD_MAX);
    // Mode d'emploi :
    //
    // Contrat :
    //

    Ensemble(int valeur[], unsigned int nbElements);

   void Afficher(void);

   void tri(void);

   bool EstEgal(const Ensemble & unEnsemble) const;

   crduEstInclus EstInclus(const Ensemble & unEnsemble)const;
   
   crduAjouter Ajouter(int aAjouter);

   unsigned int Ajuster(int delta);

//------------------------------------------------- Surcharge d'opérateurs
 /*   Ensemble & operator = ( const Ensemble & unEnsemble );
    // Mode d'emploi :
    //
    // Contrat :
    //
*/

//-------------------------------------------- Constructeurs - destructeur
 //   Ensemble ( const Ensemble & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    virtual ~Ensemble ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
unsigned int cardMax;
unsigned int cardActuelle;
int *elements;
};

//-------------------------------- Autres définitions dépendantes de <Ensemble>

#endif // Ensemble_H

