#include "colonne.h"
#include "dataframe.h"
int main() {

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

    DF*df = create_empty_DF();
    //df->colonne = malloc(5*sizeof(COLUMN));
    char titre[40];
    scanf(" %s",titre);
    printf("%s\n",titre);
    int i;
    scanf("%d",&i);
    printf("%d\n",i);
    add_column(df,titre);
    printf("%s\n",df->colonne[df->nb_colonne-1]->titre);
    add_line(df);
    printf("test2\n");
    print_df(df);
    printf("test3\n");
    delete_column_df(df,0);
    printf("test4\n");
    add_column(df,"hcfhcfh");
    printf("test5\n");
    print_df(df);


    return 0;
}