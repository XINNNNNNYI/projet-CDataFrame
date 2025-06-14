#include <stdio.h>
#include <stdlib.h>
#include "colonne.h"

Column* create_column(char* titre) {
    Column* col = malloc(sizeof(Column));
    if (col == NULL) return NULL;
    col->titre = titre;
    col->donnees = NULL;
    col->taille_physique = 0;
    col->taille_logique = 0;
    return col;
}

// Fonction ajoutant une valeur à la colonne
int insert_value(Column* col, int value) {
    if (col == NULL)
        return 0;

    if (col->taille_physique == 0) {
        col->donnees = malloc(REALLOC_SIZE * sizeof(int));
        if (col->donnees == NULL)
            return 0;
        col->taille_physique = REALLOC_SIZE;
    }
    else if (col->taille_logique >= col->taille_physique) {
        int* data = realloc(col->donnees, (col->taille_physique + REALLOC_SIZE) * sizeof(int));
        if (data == NULL)
            return 0;
        col->donnees = data;
        col->taille_physique += REALLOC_SIZE;
    }

    col->donnees[col->taille_logique++] = value;
    return 1;
}

void delete_column(Column* col) {
    if (col != NULL) {
        free(col->titre);
        free(col->donnees);
        free(col);
    }
}

void print_col(Column* col) {
    if (col != NULL) {
        for (int i = 0; i < col->taille_logique; i++) {
            printf("[%d] %d\n", i, col->donnees[i]);
        }
    }
}

int nombre_occurences(Column* col, int valeur) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique; i++) {
        if (col->donnees[i] == valeur) {
            oc++;
        }
    }
    return oc;
}

int indice_position(Column* col, int pos) {
    if (pos >= col->taille_logique)
        return 0;
    return col->donnees[pos];
}

int valeur_superieure(Column* col, int valeur) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique; i++) {
        if (col->donnees[i] > valeur) {
            oc++;
        }
    }
    return oc;
}

int valeur_inferieure(Column* col, int valeur) {
    int oc = 0;
    for (int i = 0; i < col->taille_logique; i++) {
        if (col->donnees[i] < valeur) {
            oc++;
        }
    }
    return oc;
}
