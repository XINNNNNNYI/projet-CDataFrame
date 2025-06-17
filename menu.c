#include <stdio.h>
#include "dataframe.h"

void menu() {
    DF*df = create_empty_DF();
    int option=-1;
    while(option!=0) {
        printf("\n\nChoisir une option : \n "
           "[1] - Ajouter une colonne (saisie aussi les donnees manquants) \n "
           "[2] - Ajouter une ligne (saisie aussi les donnees manquants)\n "
           "[3] - Suprimer une ligne\n "
           "[4] - Suprimer une colonne\n "
           "[5] - Afficher (df, colonne, ligne)\n "
           "[6] - Renomer une colonne\n "
           "[7] - Autres fonctionnalites\n "
           "[0] - Quitter\n ");
        if (!scanf("%d", &option)) {
            printf("ECRIS DES CHIFFRES STP \n");
            clear_buffer();
            continue;
        }
        switch (option) {
            case 1: {
                add_column(df);
                break;
            }
            case 2: {
                add_line(df);
                break;
            }
            case 3: {
                int line_index;
                printf("Quel ligne souhaiteriez vous supprimer ? (saisir l'indice) \n");
                clear_buffer();
                if (!scanf("%d", &line_index)) {
                    printf("ECRIS DES CHIFFRES STP \n");
                    continue;
                }
                delete_line(df,line_index);
                break;
            }
            case 4: {
                int column_index;
                printf("Quel colonne souhaiteriez vous supprimer ? (saisir l'indice)\n ");
                clear_buffer();
                if (!scanf("%d", &column_index)) {
                    printf("ECRIS DES CHIFFRES STP \n");
                    continue;
                }
                delete_column_df(df,column_index);
                break;
            }
            case 5: {
                int option_print;
                printf("\nQue voulez-vous afficher ?\n "
                    "[1] - La dataframe entiere \n "
                    "[2] - Une partie des colonnes\n "
                    "[3] - Une partie des lignes\n "
                    "[4] - Le nombre de ligne(s)\n "
                    "[5] - Le nombre de colonne(s)\n "
                    "[0] - Revenir en arriere\n ");
                clear_buffer();
                if (!scanf("%d", &option_print)) {
                    printf("ECRIS DES CHIFFRES STP \n");
                    continue;
                }
                switch(option_print) {
                    case 1: {
                        print_df(df);
                        break;
                    }
                    case 2: {
                        int column_index;
                        printf("Quel colonne voulez vous \n");
                        clear_buffer();
                        if (!scanf("%d", &column_index)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        print_column_df(df,column_index);
                        break;
                    }
                    case 3: {
                        int line_index;
                        printf("Quel ligne voulez vous \n");
                        clear_buffer();
                        if (!scanf("%d", &line_index)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        print_line_df(df,line_index);
                        break;
                    }
                    case 4: {
                        print_nb_line(df);
                        break;
                    }
                    case 5: {
                        print_nb_column(df);
                        break;
                    }
                    case 0: {
                        break;
                    }
                    default: {
                        printf("Votre option n'est pas valide !\n");
                        break;
                    }
                }
                break;
            }
            case 6: {
                char new_title[50];
                int num_column;
                printf("Tu veux renomer quel colonne ? (choisir un chiffre)\n");
                clear_buffer();
                if (!scanf("%d", &num_column)) {
                    printf("ECRIS DES CHIFFRES STP \n");
                    continue;
                }
                printf("Tu veux le renommer comment ?\n");
                clear_buffer();
                scanf("%49s",new_title);
                rename_column(df,num_column,new_title);
                break;
            }
            case 7: {
                int option_p;
                printf("\n Que voulez-vous faire ?\n "
                   "[1] - Regarder si une valeur existe\n "
                   "[2] - Regarder le nombre de cellules contenant une valeur egale a x (x a saisie)\n "
                   "[3] - Regarder le nombre de cellules contenant une valeur superieure a x (x a saisir)\n "
                   "[4] - Regarder le nombre de cellules contenant une valeur inferieure a x (x a saisir)\n "
                   "[5] - Regarder le nombre d'occurences d'une valeur (valeur a saisir)\n "
                   "[6] - Remplacer une valeur\n "
                   "[0] - \n ");
                clear_buffer();
                if (!scanf("%d", &option_p)) {
                    printf("ECRIS DES CHIFFRES STP \n");
                    continue;
                }
                switch(option_p) {
                    case 1: {
                        int value;
                        printf("Pour quel valeur voulez vous regarder ? \n");
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        if (value_exists(df,value) == 1 ) {
                            printf("la valeur existe ! \n");
                        }
                        else {
                            printf("La valeur n'existe pas ! \n");
                        }
                        break;
                    }
                    case 2: {
                        int value;
                        printf("Pour quel valeur voulez vous regarder ? \n");
                        clear_buffer();
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("Il y a %d valeur(s) egale a %d \n",nb_value_equal(df,value),value);
                        break;
                    }
                    case 3: {
                        int value;
                        printf("Pour quel valeur voulez vous regarder ? \n");
                        clear_buffer();
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("Il y a %d valeur(s) superieur a %d \n",nb_value_sup(df,value),value);
                        break;
                    }
                    case 4: {
                        int value;
                        printf("Pour quel valeur voulez vous regarder ? \n");
                        clear_buffer();
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("Il y a %d valeur(s) inferieur a %d \n",nb_value_inf(df,value),value);
                        break;
                    }
                    case 5: {
                        int value;
                        printf("Pour quel valeur voulez vous regarder ? \n");
                        clear_buffer();
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("La valeur %d apparait %d fois \n",value,nb_occ(df,value));
                        break;
                    }
                    case 6: {
                        int value;
                        int nb_line_i;
                        int nb_column_j;
                        printf("Quel est la ligne de la valeur que vous voulez changer ?\n");
                        clear_buffer();
                        if (!scanf("%d", &nb_line_i)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("Quel est la colonne de la valeur que vous voulez changer ?\n");
                        clear_buffer();
                        if (!scanf("%d", &nb_column_j)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        printf("Vous voulez changer en quel valeur ? \n");
                        clear_buffer();
                        if (!scanf("%d", &value)) {
                            printf("ECRIS DES CHIFFRES STP \n");
                            continue;
                        }
                        replace_value(df,value,nb_line_i,nb_column_j);
                        printf("La valeur %d est normalemnt = a %d \n",value,df->colonne[nb_column_j]->donnee[df->index[nb_line_i]]);
                        break;
                    }
                    case 7: {
                        break;
                    }
                    default: {
                        printf("Votre option n'est pas valide !\n");
                        break;
                    }
                }
                break;
            }
            case 0: {
                printf("Fermeture du programme...");
                delete_df(df);
                return;
            }
            default: {
                printf("Votre option n'est pas valide, veuillez saisir une bonne option !\n");
                break;
            }
        }
    }
}
