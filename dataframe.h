#ifndef PROJET_C_DATAFRAME_H
#define PROJET_C_DATAFRAME_H
#include "colonne.h"

typedef struct dataframe{
    COLUMN **colonne;
    int nb_ligne;
    int nb_colonne;
}DF;

DF* create_empty_DF();




#endif