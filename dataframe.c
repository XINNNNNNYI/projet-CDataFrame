#include "dataframe.h"
#include "colonne.h"

DF * create_empty_DF() {
    DF *df= malloc(sizeof(DF));
    if (df==NULL)
        return NULL;
    df->colonne = NULL;
    df->nb_colonne = 0;
    df->nb_ligne = 0;
}

void ajouter_colonne(DF*df) {
    char*titre;
    scanf("%s", titre);
    COLUMN* new_cl = create_column(titre);
    df->colonne = &new_cl;
    df->nb_colonne++;
}

void ajouter_ligne(DF*df) {

    df->nb_ligne++;
}