#ifndef PROJET_C_COLONNE_H
#define PROJET_C_COLONNE_H

# include <stdlib.h>
# include <stdio.h>

#define REALLOC_SIZE 256

typedef struct{
    char*titre;
    int *donnee;
    int taille_physique;
    int taille_logique;
}COLUMN;

/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/
COLUMN*create_column(char*titre);

/**
* @brief : Add a new value to a column
* @param1 : Pointer to a column
* @param2 : The value to be added
* @return : 1 if the value is added 0 otherwise
*/
int insert_value(COLUMN*col, int value);

/**
* @brief : Free allocated memory
* @param1 : Pointer to a column
*/
void delete_column(COLUMN*col);

/**
* @brief: Print a column content
* @param: Pointer to a column
*/
void print_col(COLUMN*col);

/**
 * 
 * @param1 : Pointer to a column
 * @param2 : La valeur dont tu veux connaitre l'occurence
 * @return int du nombre de fois que valeur apparait
 */
int nombre_occureneces(COLUMN*col, int valeur);

/**
 *
 * @param1 col Pointeur sur une colonne
 * @param valeur dont tu veux connaitre sa position
 * @return int de l'indice de la position de valeure
 */
int valeur_pos(COLUMN*col, int valeur);

/**
 *
 * @param col pointeur sur une colonne
 * @param valeur dont tu veux connaitre son nb de valeur superieur
 * @return int du nb de valeur inf à val
 */
int nb_valeur_supereur(COLUMN*col, int val);

/**
 *
 * @param col pointeur sur une colonne
 * @param valeur dont tu veux connaitre son nb de valeur inf
 * @return int du nombre de valeur inf à val
 */
int nb_valeur_inferieur(COLUMN*col, int val);

int nb_valeur_egale(COLUMN*col, int valeur);

#endif