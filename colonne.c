#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"

COLUMN*create_column(char *titre){
    COLUMN*col=malloc(sizeof(COLUMN));
    if(col==NULL)
        return NULL;
    col->titre = NULL;
    col->titre=strdup(titre);
    col->donnee = malloc(REALLOC_SIZE * sizeof(int));
    if (col->donnee == NULL) {
        printf("Erreur de malloc pour la colonne de donnee\n");
        return NULL;
    }
    col->taille_physique = REALLOC_SIZE;
    col->taille_logique=0;
    return col;
}

int insert_value(COLUMN*col, int value){
    if(col->taille_physique==0) {
        col->donnee = malloc(REALLOC_SIZE * sizeof(int));
        if (col->donnee == NULL) {
            printf("Erreur de malloc\n");
            return 0;
        }
        col->taille_physique = REALLOC_SIZE;
    }
    else if(col->taille_logique >= col->taille_physique ) {
        int *data=realloc(col->donnee,(col->taille_physique+REALLOC_SIZE)*sizeof(int));
        if (data==NULL){
            printf("Erreur de realloc\n");
            return 0;
        }
        col->taille_physique+=REALLOC_SIZE;
        col->donnee=data;
        return 2;
    }
    else if (col->taille_logique < col->taille_physique) {
        col->donnee[col->taille_logique++] = value;
    } else {
        printf("Erreur : taille logique depasse taille physique.\n");
        return 0;
    }
    if (col->donnee[col->taille_logique-1] != value) {
        printf("Erreur, la valeur n'a pas bien ete insert\n");
        return 0;
    }
    return 1;
}

int insert_value_i(COLUMN*col, int value,int num_line) {
    if (num_line < col->taille_physique) {
        col->donnee[num_line] = value;
        col->taille_logique++;
    }
    if (col->donnee[num_line] != value) {
        printf("Erreur, la valeur n'a pas bien ete insert\n");
        return 0;
    }
    if (num_line > col->taille_logique) {
        col->donnee[num_line] = value;
        col->taille_logique++;
    }
    if(num_line >= col->taille_physique) {
        int *data=realloc(col->donnee,(col->taille_physique+REALLOC_SIZE)*sizeof(int));
        if (data==NULL){
            printf("Erreur de realloc\n");
            return 0;
        }
        col->taille_physique+=REALLOC_SIZE;
        col->donnee=data;
        return 2;
    }
    return 1;
}

void delete_column(COLUMN*col) {
    free(col->donnee);
    free(col);
    col = NULL;
}

void print_col(COLUMN*col){
    if(col->donnee==NULL)
        printf("%s : non initialise ! \n", col->titre);
    else
        for (int i = 0; i < (col->taille_logique); i++) {
            printf("[%d] %d\n", i, col->donnee[i]);
        }
}

int nombre_occureneces(COLUMN*col, int valeur){
    if (col->donnee == NULL) {
        printf("Erreur : colonne non initialisee.\n");
        return -1;
    }
    printf("Valeur recherchee : %d\n", valeur);

    int oc=0;
    for(int i=0; i< col->taille_logique; i++){
        if(col->donnee[i]==valeur){
            oc++;
        }
    }
    return oc;
}

int valeur_pos(COLUMN*col, int indice){
    if(indice>=col->taille_logique || indice<0) {
        printf("erreur : la position est hors limite\n");
        return -1;
    }
    printf("Valeur pos : %d \n", col->donnee[indice]);
    return col->donnee[indice];
}

int nb_valeur_supereur(COLUMN*col, int valeure) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnee[i] > valeure) {
            oc++;
        }
    }
    return oc;
}

int nb_valeur_inferieur(COLUMN*col, int valeur) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnee[i] < valeur) {
            oc++;
        }
    }
    return oc;
}

int nb_valeur_egale(COLUMN*col, int valeur) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique;i++) {
        if (col->donnee[i] == valeur) {
            oc++;
        }
    }
    return oc;
}




