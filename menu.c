#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_colonne.h"

int main() {
    Column* col = NULL;
    int running = 1;
    int choix;

    while (running) {
        printf("\n=== MENU TEST COLONNE ===\n");
        printf("1. Créer une colonne d'entiers\n");
        printf("2. Insérer une valeur\n");
        printf("3. Afficher la colonne (ordre d'insertion)\n");
        printf("4. Afficher la colonne triée (croissant)\n");
        printf("5. Afficher la colonne triée (décroissant)\n");
        printf("6. Trier la colonne (croissant)\n");
        printf("7. Trier la colonne (décroissant)\n");
        printf("8. Infos colonne\n");
        printf("9. Supprimer la colonne\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                if (col) delete_column(col);
                col = create_column(INT, "Test");
                printf("Colonne créée.\n");
                break;
            case 2: {
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                int val;
                printf("Entrez une valeur entière à insérer : ");
                scanf("%d", &val);
                insert_value(col, &val);
                printf("Valeur insérée.\n");
                break;
            }
            case 3:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                print_col(col);
                break;
            case 4:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                print_col_sorted(*col, croiss);
                break;
            case 5:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                print_col_sorted(*col, decroiss);
                break;
            case 6:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                sort(col, croiss);
                printf("Colonne triée (croissant).\n");
                break;
            case 7:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                sort(col, decroiss);
                printf("Colonne triée (décroissant).\n");
                break;
            case 8:
                if (!col) { printf("Créez d'abord une colonne.\n"); break; }
                info_column(col);
                break;
            case 9:
                if (col) {
                    delete_column(col);
                    col = NULL;
                    printf("Colonne supprimée.\n");
                } else {
                    printf("Aucune colonne à supprimer.\n");
                }
                break;
            case 0:
                running = 0;
                if (col) delete_column(col);
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    }
    return 0;
}



