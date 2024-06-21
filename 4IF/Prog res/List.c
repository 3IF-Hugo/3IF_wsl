/* Pour lister tous les mots, Exemple de structure de données complexes */
const MAXMOTLONG = 255;                   /* Taille maxi mot */
typedef string chaine_mot<MAXMOTLONG>;    /* Un mot pour chaînage, indispensable */
typedef struct  list_mots* suivant_list; /* Suivant dans la liste */

struct list_mots {
    chaine_mot mot;            /* Le mot */
    suivant_list mot_suivant;  /* Pointeur vers le suivant */
};
//Initialisation de la liste
suivant_list liste_mots = NULL;

//vider la liste
void vider_liste(suivant_list* liste)
{
    suivant_list courant = *liste;
    suivant_list suivant = NULL;
    while (courant != NULL) {
        suivant = courant->mot_suivant;
        free(courant);
        courant = suivant;
    }
    *liste = NULL;
}

//insertion en tête mot dans liste
void inserer_mot(suivant_list* liste, chaine_mot mot)
{
    suivant_list nouveau = malloc(sizeof(struct list_mots));
    strcpy(nouveau->mot, mot);
    nouveau->mot_suivant = *liste;
    *liste = nouveau;
}

//Suppression d'un mot dans la liste
void supprimer_mot(suivant_list* liste, chaine_mot mot)
{
    suivant_list courant = *liste;
    suivant_list precedent = NULL;
    while (courant != NULL) {
        if (strcmp(courant->mot, mot) == 0) {
            if (precedent == NULL) {
                *liste = courant->mot_suivant;
            } else {
                precedent->mot_suivant = courant->mot_suivant;
            }
            free(courant);
            return;
        }
        precedent = courant;
        courant = courant->mot_suivant;
    }
}

//Affichage de la liste
void afficher_liste(suivant_list liste)
{
    suivant_list courant = liste;
    while (courant != NULL) {
        printf("%s ", courant->mot);
        courant = courant->mot_suivant;
    }
    printf("\n");
}

