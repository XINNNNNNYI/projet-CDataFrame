#ifndef PROJET_C_COLONNE_H
#define PROJET_C_COLONNE_H
#define REALLOC_Size 256
typedef struct{
    char*titre;
    int donnée;
    int taille_physique;
    int taille_logique;
}COLUMM;
COLUMN*create_column(char*titre);
int insert_value(COLUMN$col, int value);
void delete_column(COLUMN*col);
void print_col(COLUMN*col);
int nombre_occureneces(COLLUMN*col, int valeure);
int indice_position(COLUMN*col, int valeure);
int valeur_supereur(COLUMN*col, int valeure);
int valeur_inferieur(COLUMN*col, int valeure);




#endif //PROJET_C_COLONNE_H
