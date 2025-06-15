#ifndef PROJET_C_DATAFRAME_H
#define PROJET_C_DATAFRAME_H
#include "colonne.h"

typedef struct dataframe{
    COLUMN **colonne;
    int nb_ligne;
    int nb_colonne;
    int*index;
}DF;

DF*create_empty_DF();

void fill_line_df(DF*df,int line_index);

void fill_column_df(DF*df,int column_index);

void print_df(DF*df);

void print_line_df(DF*df,int nb_ligne_a_print);

void print_column_df(DF*df,int nb_colonne_a_print);

void add_column(DF *df,char*titre);

void delete_column_df(DF*df,int indice);

void add_line(DF *df);

void delete_line(DF*df,int indice);

void delete_df(DF*df);

void rename_column(DF*df, int num_column,char*new_title);

int value_exists(DF*df, int value);

void replace_value(DF*df, int value,int nb_line_i,int nb_column_j);

void print_nb_column(DF*df);

void print_nb_line(DF*df);

int nb_value_sup(DF*df, int val);

int nb_value_inf(DF*df, int val);

int nb_value_equal(DF*df, int val);

int nb_occ(DF*df, int val);

void menu();

#endif