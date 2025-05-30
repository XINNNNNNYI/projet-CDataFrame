#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"
COLUMN*create_column(char*titre){
    COLUMN*col=malloc(sizeof(COLUMN));
    if(col==NULL) return NULL;
    col->titre=titre;
    col->donnee=NULL;
    col->taille_physique=0;
    col->taille_logique=0;
    return col;


}
// fonction ajoutant une valeur à la colonne
int insert_value(COLUMN*col, int value){
    if(col==NULL)
        return 0;
    if(col->taile_physique==0) {
        col->donnee = malloc(REALLOC_Size * sizeof(int));
        if (col->donnee == NULL)
            return 0;
        col->taille_physique = REALLOC_SIZE;
    }
    else if(col->taille_physique >= col->taille_logique ){
        int *data=realloc(col->donnee,(col->taille_physqiue+REALLOC_Size));
        if (dat==NULL)
            return 0;
        col->taille_physique+=REALLOC_Size
        col->donnee=data;}
    col->donnee[col->taille_logique++]  = value;


    return 1:}
void delete_column(COLUMN*col) {
    if (col != NULL) {
        free(col->titre);
        free(col->donnee);
        free(col);
    }
}
void print_col(COLUMN*col){

    if(col!=NULL) {
        for (int i = 0; i < (col->taille_logique), i++) {
            printf("[%d] %d", i, col->donnee[i])


        }
    }
}
int nombre_occureneces(COLLUMN*col, int valeure){
    int oc=0;
    for(int i=0; i<col->taille_loique){
        if(c->donnee[i]==valeure){
            oc++;
        }

    }
    return oc;
}
int indice_position(COLUMN*col, int pos){
    if(pos>=col->taille_logique)
        return 0;
   return col->donnee[pos]);
}
int valeur_supereur(COLLUMN*col, int valeure) {
    int oc = 0;
    for (int i = 0; i < col->taille_loique) {
        if (c->donnee[i] > valeure) {
            oc++;
        }

    }
    return oc;
}

int valeur_inferieur(COLLUMN*col, int valeure) {
    int oc = 0;
    for (int i = 0; i < col->taille_loique) {
        if (c->donnee[i] < valeure) {
            oc++;
        }

    }
    return oc;
}


