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

void delete_column_df(DF*df,int indice);

void add_line(DF *df);

void delete_line(DF*df,int indice);

void rename_column(DF*df, int nb_column,char*new_title);

int value_exists(DF*df, int value);

void replace_value(DF*df, int value);

void print_nb_column(DF*df);

void print_nb_line(DF*df);

int nb_value_sup(DF*df, int val);

int nb_value_inf(DF*df, int val);

int nb_value_equal(DF*df, int val);

#endif