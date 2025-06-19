#include <stdio.h>
#include <stdlib.h>
#include "new_colonne.h"

Enum_Type demander_type_colonne() {
    int choix = -1;
    printf("Choisissez le type de colonne :\n");
    printf("1. UINT\n");
    printf("2. INT\n");
    printf("3. CHAR\n");
    printf("4. FLOAT\n");
    printf("5. DOUBLE\n");
    printf("6. STRING\n");
    printf("7. USHORT\n");
    printf("8. OBJECT\n");
    printf("9. SHORT\n");
    printf("10. ULONG\n");
    printf("11. LONG\n");
    printf("12. UCHAR\n");
    printf("Votre choix : \n");
    scanf("%d", &choix);

    switch (choix) {
        case 1: return UINT;
        case 2: return INT;
        case 3: return CHAR;
        case 4: return FLOAT;
        case 5: return DOUBLE;
        case 6: return STRING;
        case 7: return USHORT;
        case 8: return OBJECT;
        case 9: return SHORT;
        case 10: return ULONG;
        case 11: return LONG;
        case 12: return UCHAR;
        default:
            printf("Choix invalide, type UINT sélectionné par défaut.\n");
            return UINT;
    }
}

int main() {
    Column* col = NULL;
    
    int choix=-1;

    while (choix!= 0) {
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
                Enum_Type type = demander_type_colonne();
                col = create_column(type, "Test");
                printf("Colonne créée de type %d.\n", type);
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
                choix = 0;
                if (col) delete_column(col);
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    }
    return 0;
}







