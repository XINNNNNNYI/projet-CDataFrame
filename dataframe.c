#include "dataframe.h"
#include "colonne.h"


void clear_buffer() {
    while (getchar()!='\n');
}

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
    clear_buffer();
    printf("test\n");
    for (int i = ligne; i < df->nb_ligne; i++) {
        for (int j = 0; j < df->nb_colonne; j++) {
            clear_buffer();
            scanf("%d",&value);
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
        printf("combien de ligne tu veux print ? \n");
        clear_buffer();
        scanf("%d",&nb_ligne_a_print);
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
        clear_buffer();
        scanf("%d",&nb_colonne_a_print);
        for (int i = 0; i < nb_colonne_a_print; i++) {
            printf("Colonne [%d] : ",i);
            print_col(df->colonne[i]);
        }
    }
}

void add_column(DF*df) {
    char*titre= NULL;
    printf("Titre de la colonne ?\n ");
    clear_buffer();
    scanf("%s", titre);
    COLUMN* new_cl = create_column(titre);
    printf("Test\n ");
    df->colonne[0] = new_cl;

    df->nb_colonne++;
}

void delete_column_df(DF*df, int indice) {
    delete_column(df->colonne[indice]);
}

void add_line(DF*df) {
    for (int i = 0; i < df->nb_colonne; i++) {
        fill_df(df);
    }
    df->nb_ligne++;
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

void replace_value(DF*df, int value) {
    int nb_ligne_i;
    int nb_colonne_j;
    printf("tu veux remplacer quel valeur ? (saisir nb_ligne/nb_colonne");
    clear_buffer();
    scanf("%d/%d",&nb_ligne_i,&nb_colonne_j);
    df->colonne[nb_colonne_j]->donnee[nb_ligne_i] = value;
}

void print_nb_column(DF*df) {
    printf("Le nombre de colonne est de : %d \n",df->nb_colonne);

}
