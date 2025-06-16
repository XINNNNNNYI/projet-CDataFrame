#include "colonne.h"
#include "dataframe.h"
#include <stdio.h>
int main() {
    printf("----------------------------------------------\n"
        "|              Projet CDataFrame             |\n"
        "|                                            |\n"
        "|         Realise par les etudiantes :       |\n"
        "|            ZHAN Xinyi                      |\n"
        "|            MOUMSIK Marwa                   |\n"
        "|            BONNEFOND Juliette              |\n"
        "|                                            |\n"
        "----------------------------------------------\n\n");

    /*
    COLUMN*col = create_column("Colonne");
    print_col(col);

    if (!col) {                          // <=> (col == NULL), s'il ne marche pas
        return 1;                      //return 1 car 1 =>erreur 0=>fonctionne (code erno)
    }
    for (int i = 0; i < 258; i++) {     //jusqu'a + de 256 pour voir s'il realloc bien
        if (!insert_value(col, i+1)) {
            printf("erreur\n");     //verifie s'il insère bien la valeur
            delete_column(col);
            return 1;                   //pour que le programme s'arrete entierement, pour ne pas avoir d'erreur avec valgrind
        }
    }
    print_col(col);

    printf("valeur qui a pour indice 16 : %d\n",valeur_pos(col,16));
    printf("valeur sup de 16 : %d \n",nb_valeur_supereur(col,16));
    printf("val inf de 16 : %d \n", nb_valeur_inferieur(col,16));
    printf("nb occurence : %d\n", nombre_occureneces(col,16));
    delete_column(col);
    **/
    /**
    DF*df = create_empty_DF();
    //df->colonne = malloc(5*sizeof(COLUMN));
    char titre[40];
    scanf(" %s",titre);
    printf("%s\n",titre);
    add_column(df,titre);
    //printf("le titre : %s\n",df->colonne[df->nb_colonne-1]->titre);
    add_line(df);
    //printf("index 0 : %d\n",df->index[0]);
    //printf("nb de ligne : %d\n",df->nb_ligne);
    print_df(df);
    //printf("taille logique : %d\n",df->colonne[0]->taille_logique);
    printf("je vais supp la colonne \n");
    add_column(df,"2");
    delete_column_df(df,0);
    add_column(df,"3");
    print_df(df);
    add_line(df);
    print_df(df);
    */
    menu();
    return 0;
}