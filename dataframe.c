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
    for (int i = 0; i < df->nb_ligne; i++) {
        for (int j = 0; j < df->nb_colonne; j++) {
            printf("Veillez sasair la veleur de ligne [%d] et de colonne [%d]\n",i,j);
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

void print_line_df(DF *df) {
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        for (int i = 0; i < df->nb_ligne; i++) {
            printf("Ligne [%d] : ",i);
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

void add_line(DF*df) {

}