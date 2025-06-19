#include "dataframe.h"

#include <string.h>

#include "colonne.h"

void clear_buffer() {
    while(getchar()!='\n');
}
DF *create_empty_DF() {
    DF *df= malloc(sizeof(DF));
    if (df==NULL)
        return NULL;
    df->colonne = malloc(REALLOC_SIZE*sizeof(COLUMN*));
    if (df->colonne==NULL)
        return NULL;
    for(int i=0;i<REALLOC_SIZE;i++) {
        df->colonne[i] = NULL;
    }
    df->taille_colonne = REALLOC_SIZE;
    df->nb_colonne = 0;
    df->nb_ligne = 0;
    df->index = malloc(REALLOC_SIZE*sizeof(int));
    memset(df->index,-1,REALLOC_SIZE*sizeof(int));
    return df;
}

void fill_line_df(DF *df,int line_index) {
    if (df->nb_colonne == 0) {
        printf("erreur il n'y a pas de colonne\n");
        return;
    }
    int value=0;
    if (line_index > df->nb_ligne || line_index < 0) {
        printf("erreur : la ligne existe pas\n");
        return;
    }
    for (int j = 0; j < df->nb_colonne; j++) {
        printf("inserer une valeur pour la ligne %d, colonne %s : \n",line_index,df->colonne[j]->titre);
        clear_buffer();
        while (!scanf("%d", &value)) {
            printf("Veuillez saisir des chiffres\n");
            clear_buffer();
        }
        int return_insert_value = insert_value_i(df->colonne[j],value,line_index);
        if (return_insert_value == 0) {
            printf("erreur : la valeur n'est pas bien insere\n");
            delete_column(df->colonne[j]);
            return;
        }
        if (return_insert_value == 2) {
            int *data=realloc(df->index,(df->colonne[0]->taille_physique+REALLOC_SIZE)*sizeof(int));
            if (data==NULL){
                printf("Erreur de realloc\n");
                return;
            }
            for (int i = df->colonne[0]->taille_physique; i < df->colonne[0]->taille_physique+REALLOC_SIZE; i++) {
                data[i] = -1;
            }
            df->index=data;
        }
    }
}

void fill_column_df(DF *df,int column_index) {
    if (!df->colonne) {
        printf("erreur il n'y a pas de colonne\n");
        return;
    }
    if (!df->colonne[column_index]) {
        printf("erreur il n'y a pas de colonne a cette indice\n");
        return;
    }
    if (df->nb_ligne==0) {
        printf("t'as pas de ligne donc je ne vais pas pouvoir saisir de donnee !\n");
        return;
    }
    for (int i = 0; i < df->nb_ligne; i++) {
        if (df->index[i] > -1) {
            int value=0;
            printf("inserer une valeur pour la colonne %s, ligne : %d \n", df->colonne[column_index]->titre, i);
            clear_buffer();
            while (!scanf("%d", &value)) {
                printf("Veuillez saisir des chiffres\n");
                clear_buffer();
            }
            if (!insert_value(df->colonne[column_index],value)) {
                printf("erreur : la valeur n'est pas bien insere");
                delete_column(df->colonne[column_index]);
                return;
            }
        }
    }
}

void print_df(DF *df) {
    if (!df || df->nb_colonne == 0) {
        printf("DF non initialisee\n");
        return;
    }
    printf("Colonne :| ");
    for (int j = 0; j < df->taille_colonne; j++) {
        if (df->colonne[j] != NULL) {
            printf(" %s |", df->colonne[j]->titre);
        }
    }
    printf("\n");
    for (int i = 0; i < df->nb_ligne; i++) {
        if (df->index[i]>-1) {
            printf("Ligne [%d] :| ",i);
            for (int j = 0; j < df->taille_colonne; j++) {
            if (df->colonne[j] != NULL) {
                printf("%d |",df->colonne[j]->donnee[df->index[i]]);
            }
        }
            printf("\n");
        }
    }
}

void print_line_df(DF *df, int ligne_a_print) {
    if (!df) {
        printf("DF non initialisee\n");
        return;
    }
    if (ligne_a_print > df->nb_ligne) {
        printf("Erreur : ligne invalide \n");
    }
    if (df->index[ligne_a_print]>0) {
        printf("Ligne [%d] :| ",ligne_a_print);
        for (int j = 0; j < df->nb_colonne; j++) {
            if (df->colonne[j] != NULL) {
                printf("%d |",df->colonne[j]->donnee[df->index[ligne_a_print]]);
            }
        }
    }
    else {
        printf("Veillez saisir une ligne avec un indice correcte");
    }
}

void print_column_df(DF*df,int colonne_a_print) {
    if (!df) {
        printf("DF non initialisee\n");
        return;
    }
    if (colonne_a_print >= df->nb_colonne) {
        printf("Erreur : colonne invalide \n");
    }
    if (df->colonne[colonne_a_print] == NULL) {
        printf("Il n'y a pas de colonne valide \n");
        return;
    }
    if (df->colonne[colonne_a_print] != NULL || df->nb_colonne <= colonne_a_print) {
        printf("%s : ",df->colonne[colonne_a_print]->titre);
        for (int i = 0; i < df->nb_ligne; i++) {
            printf("Ligne [%d] :| ",i);
            if (df->index[i]>-1)
                printf("%d |\n",df->colonne[i]->donnee[df->index[i]]);
        }
    }
}

void add_column(DF*df) {
    char* titre = malloc(50 * sizeof(char));
    if (titre == NULL) {
        printf("ERREUR DE MALLOC \n");
        return;
    }
    printf("Insert titre : ");
    clear_buffer();
    scanf("%s",titre);
    COLUMN* new_cl = create_column(titre);
    if (new_cl==NULL){
        printf("Erreur d'allocation ! \n");
        return;
    }
    if (df->nb_colonne >= df->taille_colonne) {
        COLUMN**data = realloc(df->colonne,(df->taille_colonne+REALLOC_SIZE)*sizeof(COLUMN*));
        if (data==NULL) {
            printf("Erreur de realloc\n");
        }
        df->colonne = data;
        df->taille_colonne+=REALLOC_SIZE;
    }
    for (int i = 0; i <= df->nb_colonne; i++) {
        if (df->colonne[i]==NULL) {
            df->colonne[i] = new_cl;
            if (df->nb_ligne != 0) {
                fill_column_df(df,i);
                df->nb_colonne++;
                return;
            }
        }
    }
    df->colonne[df->nb_colonne] = new_cl;
    if (df->nb_ligne != 0) {
        fill_column_df(df,df->nb_colonne);
    }
    df->nb_colonne++;
}

void delete_column_df(DF*df, int indice) {
    if (df->colonne[indice] == NULL || indice < 0 || df->nb_colonne <= indice) {
        printf("erreur : tu peux pas supprimer une colonne qui n'existe pas ! \n");
        return;
    }
    delete_column(df->colonne[indice]);
    df->colonne[indice] = NULL;
    df->nb_colonne--;
}

void add_line(DF*df) {
    if (df->nb_colonne == 0){
        printf("Erreur : y'a  pas de colonne veillez cree un aavnt de creer un ligne ! \n");
        return;
    }
    if (df->index[df->nb_ligne] == -1 ) {
        df->index[df->nb_ligne] = df->nb_ligne;
    }
    fill_line_df(df,df->index[df->nb_ligne]);
    df->nb_ligne++;
}

void delete_line(DF*df,int indice) {
    if (df->index[indice] < 0 || indice > df->nb_ligne) {
        printf("Erreur : tu ne peux pas supprimer une ligne qui n'existe pas ! \n");
        return;
    }
    for (int i = indice; i < df->nb_ligne; i++) {
        int tmp = df->index[i];
        df->index[i] = df->index[i+1];
        df->index[i+1] = tmp;
    }
    df->nb_ligne--;
}

void delete_df(DF*df) {
    for (int i = 0; i < df->taille_colonne; i++) {
        if (df->colonne[i]) {
            delete_column(df->colonne[i]);
        }
    }
    free(df->index);
    free(df->colonne);
    free(df);
}

void rename_column(DF*df,int num_column, char*new_title) {
    if (df->colonne[num_column] == NULL) {
        printf("erreur : tu ne peux pas renommer une colonne qui n'existe pas ! \n");
        return;
    }
    df->colonne[num_column]->titre = strdup(new_title);
}

int value_exists(DF*df, int value) {
    for (int i = 0; i < df->nb_ligne; i++) {
        for (int j = 0; j < df->nb_colonne; j++) {
            if (df->colonne[j]->donnee[i] == value) {
                return 1;
            }
        }
    }
    return 0;
}

int replace_value(DF*df, int value,int nb_line_i,int nb_column_j) {
    if (df->nb_ligne < nb_line_i || df->nb_colonne < nb_column_j) {
        printf("CETTE CELLULE N'EXISTE PAS ! \n");
        return 0;
    }
    if (!df->colonne[nb_column_j]->donnee[df->index[nb_line_i]]) {
        printf("erreur : cette case n'existe pas ! \n");
        return 0;
    }
    df->colonne[nb_column_j]->donnee[df->index[nb_line_i]] = value;
    return 1;
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

int nb_occ(DF*df, int val) {
    int cpt = 0;
    for (int i = 0; i < df->nb_colonne; i++) {
        cpt += nombre_occureneces(df->colonne[i],val);
    }
    return cpt;
}
