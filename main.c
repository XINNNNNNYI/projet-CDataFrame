#include "colonne.h"
int main() {
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

    printf("valeur qui a pour indice 16 : %d \n",valeur_pos(col,16));
    printf("valeur sup de 16 : %d \n",nb_valeur_supereur(col,16));
    printf("val inf de 16 : %d \n", nb_valeur_inferieur(col,16));
    printf("nb occurence : %d\n", nombre_occureneces(col,16));
    delete_column(col);

    return 0;
}