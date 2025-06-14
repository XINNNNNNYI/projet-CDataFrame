#include "dataframe.h"

#include <string.h>

#include "colonne.h"

DF *create_empty_DF() {
    DF *df= malloc(sizeof(DF));
    if (df==NULL)
        return NULL;
    df->colonne = NULL;
    df->nb_colonne = 0;
    df->nb_ligne = 0;
    df->index = malloc(sizeof(int)*REALLOC_SIZE);
    if (df->index==NULL)
        return NULL;
    memset(df->index, -1, sizeof(int)*REALLOC_SIZE);
    df->one = 0;
    return df;
}

void fill_line_df(DF *df,int line_index) {
    int value;
    for (int j = 0; j < df->nb_colonne; j++) {
        printf("inserer une valeur ");
        scanf("%d",&value);
        insert_value(df->colonne[df->index[line_index]],value);
    }
}

void fill_column_df(DF *df) {

}

void print_df(DF *df) {
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        for (int i = 0; i < df->nb_ligne; i++) {
            printf("Ligne [%d] : ",i);
            for (int j = 0; j < df->nb_colonne; j++) {
                printf("%d ",df->colonne[j]->donnee[df->index[i]]);
            }
            printf("\n");
        }
    }
}

void print_line_df(DF *df, int nb_ligne_a_print){
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        for (int i = 0; i < nb_ligne_a_print; i++) {
            printf("Ligne [%d] : ",i);
            for (int j = 0; j < df->nb_colonne; j++) {
                printf(",%d ",df->colonne[i]->donnee[j]);
            }
        }
    }
}

void print_column_df(DF*df,int nb_colonne_a_print) {
    if (!df) {
        printf("DF non initialisee\n");
    }
    else {
        for (int i = 0; i < nb_colonne_a_print; i++) {
            printf("Colonne [%d] : ",i);
            print_col(df->colonne[i]);
        }
    }
}

void add_column(DF*df,char*titre) {
    COLUMN* new_cl = create_column(titre);
    df->colonne[df->nb_colonne] = new_cl;
    df->nb_colonne++;
}

void delete_column_df(DF*df, int indice) {
    delete_column(df->colonne[indice]);
}

void add_line(DF*df) {

    for (int i = 0; i < df->index[df->colonne[0]->taille_physique]; i++) {
        if (df->index[i]<0 ) {
            if (i < df->colonne[0]->taille_logique) {
                df->index[i] = abs(df->index[i]);
            fill_line_df(df,df->index[i]);
            }
            else {

                df->index[i] = df->nb_ligne;
                fill_line_df(df,df->index[i]);
            }
        }
    }
    df->nb_ligne++;
    df->index[df->nb_ligne-1] = df->nb_ligne-1;
}

void delete_line(DF*df,int indice) {

}

void rename_column(DF*df,int nb_column, char*new_title) {
    df->colonne[nb_column]->titre = new_title;
}

int value_exists(DF*df, int value) {
    for (int i = 0; i < df->nb_ligne; i++) {
        for (int j = 0; j < df->nb_colonne; j++) {
            if (value) {
                printf("Ligne : %d, colonne : %d \n",i,j);
                return 1;
            }
        }
    }
    return 0;
}

void replace_value(DF*df, int value,int nb_line_i,int nb_column_j) {
        df->colonne[nb_column_j]->donnee[nb_line_i] = value;
    }

void print_nb_column(DF*df) {
        printf("Le nombre de colonne est de : %d \n",df->nb_colonne);
    }

void print_nb_line(DF*df) {
        printf("Le nombre de ligne est de : %d \n", df->nb_ligne);
    }

int nb_value_sup(DF*df, int val) {
        int cpt =0;
        for (int i = 0; i < df->nb_colonne; i++) {
            cpt+=nb_valeur_supereur(df->colonne[i],val);
        }
        return cpt;
    }

int nb_value_inf(DF*df, int val) {
        int cpt =0;
        for (int i = 0; i < df->nb_colonne; i++) {
            cpt+=nb_valeur_inferieur(df->colonne[i],val);
        }
        return cpt;
    }

int nb_value_equal(DF*df, int val) {
        int cpt = 0;
        for (int i = 0; i < df->nb_colonne; i++) {
            cpt+=nb_valeur_egale(df->colonne[i],val);
        }
        return cpt;
    }
