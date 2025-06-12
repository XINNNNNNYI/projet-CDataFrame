#include "dataframe.h"
#include "colonne.h"

DF *create_empty_DF() {
    DF *df= malloc(sizeof(DF));
    if (df==NULL)
        return NULL;
    df->colonne = NULL;
    df->nb_colonne = 0;
    df->nb_ligne = 0;
    return df;
}

void fill_df(DF *df) {
    int value;
    int ligne=0;
    while (df->colonne[0]->taille_logique) {
        ligne++;
    }
    for (int i = ligne; i < df->nb_ligne; i++) {
        for (int j = 0; j < df->nb_colonne; j++) {
            printf("Veillez saisir la valeur de ligne [%d] et de colonne [%d]\n",i,j);
            scanf("&d",&value);
            insert_value(*df->colonne,value);
        }
    }
}

void print_df(DF *df) {
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        for (int i = 0; i < df->nb_ligne; i++) {
            printf("Ligne [%d] : ",i);
            for (int j = 0; j < df->nb_colonne; j++) {
                printf("%d ",df->colonne[i]->donnee[j]);
            }
            printf("\n");
        }
    }
}

void print_line_df(DF *df){
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        int nb_ligne_a_print;
        printf("combien de ligne tu veux print ? ");
        scanf("&d",&nb_ligne_a_print);
        for (int i = 0; i < nb_ligne_a_print; i++) {
            printf("Ligne [%d] : ",i);
            for (int j = 0; j < df->nb_colonne; j++) {
                printf(",%d ",df->colonne[i]->donnee[j]);
            }
        }
    }
}

void print_column_df(DF*df) {
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        int nb_colonne_a_print;
        printf("combien de colonne tu veux print ? ");
        scanf("&d",&nb_colonne_a_print);
        for (int i = 0; i < nb_colonne_a_print; i++) {
            printf("Colonne [%d] : ",i);
            print_col(df->colonne[i]);
        }
    }
}

void add_column(DF*df) {
    char*titre= NULL;
    printf("Titre de la colonne ?\n ");
    scanf("%s", titre);
    COLUMN* new_cl = create_column(titre);
    df->colonne[0] = new_cl;
    df->nb_colonne++;
}

void delete_column_df(DF*df, int indice) {
    delete_column(df->colonne[indice]);
}

void add_line(DF*df) {
    for (int i = 0; i < df->nb_colonne; i++) {
        int value=0;
        printf("Veuillez saisir la valeur de %s",df->colonne[i]->titre);
        scanf("&d",&value);
        insert_value(df->colonne[i],value);
    }
    df->nb_ligne++;
}

