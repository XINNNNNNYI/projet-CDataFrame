#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"

COLUMN*create_column(char*titre){
    COLUMN*col=malloc(sizeof(COLUMN));
    if(col==NULL)
        return NULL;
    col->titre=titre;
    col->donnee=NULL;
    col->taille_physique=0;
    col->taille_logique=0;
    return col;
}

int insert_value(COLUMN*col, int value){
    if(col->taille_physique==0) {
        col->donnee = malloc(REALLOC_SIZE * sizeof(int));
        if (col->donnee == 0)
            return 0;
        col->taille_physique = REALLOC_SIZE;
    }
    else if(col->taille_logique >= col->taille_physique ){
        int *data=realloc(col->donnee,(col->taille_physique+REALLOC_SIZE));
        if (data==NULL)
            return 0;
        col->taille_physique+=REALLOC_SIZE;
        col->donnee=data;}
    col->donnee[col->taille_logique++]  = value;
    return 1;
}

void delete_column(COLUMN*col) {
    free(col);
    col = NULL;
}

void print_col(COLUMN*col){
    if(col->donnee==NULL)
        printf("Y'a rien ! \n");
    else
        for (int i = 0; i < (col->taille_logique); i++) {
            printf("[%d] %d\n", i, col->donnee[i]);
        }
}

int nombre_occureneces(COLUMN*col, int valeure){
    int oc=0;
    for(int i=0; i< col->taille_logique; i++){
        if(col->donnee[i]==valeure){
            oc++;
        }

    }
    return oc;
}

int indice_position(COLUMN*col, int pos){
    if(pos>=col->taille_logique)
        return 0;
    return col->donnee[pos];
}

int valeur_supereur(COLUMN*col, int valeure) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnee[i] > valeure) {
            oc++;
        }
    }
    return oc;
}

int valeur_inferieur(COLUMN*col, int valeure) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnee[i] < valeure) {
            oc++;
        }
    }
    return oc;
}

