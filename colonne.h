#ifndef PROJET_C_COLONNE_H
#define PROJET_C_COLONNE_H

#include <stdio.h>

#define REALLOC_SIZE 256

typedef struct {
    char* titre;
    int* donnees;
    int taille_physique;
    int taille_logique;
} Column;

Column* create_column(char* titre);
void insert_value(Column* col, int value);
void delete_column(Column* col);
void print_col(Column* col);
int nombre_occurences(Column* col, int valeur);
int indice_position(Column* col, int valeur);
int valeur_superieure(Column* col, int valeur);
int valeur_inferieure(Column* col, int valeur);

#endif
