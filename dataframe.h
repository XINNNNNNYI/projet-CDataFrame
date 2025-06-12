#ifndef PROJET_C_DATAFRAME_H
#define PROJET_C_DATAFRAME_H
#include "colonne.h"

typedef struct dataframe{
    COLUMN **colonne;
    int nb_ligne;
    int nb_colonne;
}DF;

DF*create_empty_DF();

void fill_df(DF*df);

void print_df(DF*df);

void print_line_df(DF*df);

void print_column_df(DF*df);

void add_column(DF *df);

void add_line(DF *df);






#endif