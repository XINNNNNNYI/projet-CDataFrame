#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_colonne.h"

Column* create_column(Enum_Type type, char* titre) {
    Column* col = (Column*) malloc(sizeof(Column));
    if (col == NULL)
        return NULL;

    col->titre = strdup(titre);
    col->column_type = type;
    col->taille_logique = 0;
    col->taille_physique = 0;
    col->donnee = NULL;
    col->index = NULL;
    col->valid_index = 0;
    col->sort_dir = 0;
    col->index_size = 0;

    return col;
}

void insert_value(Column* col, void* value) {
    if (col == NULL || value == NULL)
        return ;

    if (col->taille_physique == 0) {
        col->donnee = malloc(REALLOC_SIZE * sizeof(Column_Type *));
        if (col->donnee == NULL)
            return ;
        col->taille_physique = REALLOC_SIZE;
    } else if (col->taille_logique >= col->taille_physique) {
        Column_Type **data = realloc(col->donnee, (col->taille_physique + REALLOC_SIZE) * sizeof(Column_Type *));
        if (data == NULL)
            return ;
        col->donnee = data;
        col->taille_physique += REALLOC_SIZE;
    }
    switch (col->column_type) {
        case INT:
            col->donnee[col->taille_logique] = malloc(sizeof(int));
            *((int *) col->donnee[col->taille_logique]) = *((int *) value);
            break;
        case UINT:
            col->donnee[col->taille_logique] = malloc(sizeof(unsigned int));
            *((unsigned int *) col->donnee[col->taille_logique]) = *((unsigned int *) value);
            break;
        case USHORT:
            col->donnee[col->taille_logique] = malloc(sizeof(unsigned short));
            *((unsigned short *) col->donnee[col->taille_logique]) = *((unsigned short *) value);
            break;
        case SHORT:
            col->donnee[col->taille_logique] = malloc(sizeof(short));
            *((short *) col->donnee[col->taille_logique]) = *((short *) value);
            break;
        case ULONG:
            col->donnee[col->taille_logique] = malloc(sizeof(unsigned long long int));
            *((unsigned long long int *) col->donnee[col->taille_logique]) = *((unsigned long long int *) value);
            break;
        case LONG:
            col->donnee[col->taille_logique] = malloc(sizeof(signed long long int));
            *((signed long long int *) col->donnee[col->taille_logique]) = *((signed long long int *) value);
            break;
        case UCHAR:
            col->donnee[col->taille_logique] = malloc(sizeof(unsigned char));
            *((unsigned char *) col->donnee[col->taille_logique]) = *((unsigned char *) value);
            break;
        case CHAR:
            col->donnee[col->taille_logique] = malloc(sizeof(signed char));
            *((signed char *) col->donnee[col->taille_logique]) = *((signed char *) value);
            break;
        case FLOAT:
            col->donnee[col->taille_logique] = malloc(sizeof(float));
            *((float *) col->donnee[col->taille_logique]) = *((float *) value);
            break;
        case DOUBLE:
            col->donnee[col->taille_logique] = malloc(sizeof(double));
            *((double *) col->donnee[col->taille_logique]) = *((double *) value);
            break;
        case STRING:
            col->donnee[col->taille_logique] = malloc(sizeof(char *));
            *((char **) col->donnee[col->taille_logique]) = *((char **) value);
            break;
        case OBJECT:
            col->donnee[col->taille_logique] = malloc(sizeof(void *));
            *((void **) col->donnee[col->taille_logique]) = *((void **) value);
            break;
        default:
            printf("le type de valeur est non géré");
            return ;
    }

    col->taille_logique++;
    return ;
}

void delete_column(Column* col){
    if (col != NULL) {
        free(col->titre);
        if (col->donnee != NULL) {
            for (unsigned int i = 0; i < col->taille_logique; i++) {
                free(col->donnee[i]);
            }
            free(col->donnee);
        }
        free(col);
    }
}

void print_object(Objet_value* ob, char* str, unsigned int taille_logique) {
    if (!ob || !str || taille_logique == 0) return;
    switch (ob->type) {
        case OBJECT_INT:
            snprintf(str, taille_logique, "%d", ob->value.int_value);
            break;
        case OBJECT_UNINT:
            snprintf(str, taille_logique, "%u", ob->value.uint_value);
            break;
        case OBJECT_CHAR:
            snprintf(str, taille_logique, "%c", ob->value.char_value);
            break;
        case OBJECT_FLOAT:
            snprintf(str, taille_logique, "%f", ob->value.float_value);
            break;
        case OBJECT_DOUBLE:
            snprintf(str, taille_logique, "%lf", ob->value.double_value);
            break;
        case OBJECT_STRING:
            snprintf(str, taille_logique, "%s", ob->value.string_value);
            break;
    }
}

void print_value(Column* col, unsigned long long int i, char* str, unsigned int taille_logique) {
    if (col == NULL || str == NULL || i >= col->taille_logique) {
        return;
    }
    switch (col->column_type) {
        case INT:
            snprintf(str, taille_logique, "%d", *((int *) col->donnee[i]));
            break;
        case UINT:
            snprintf(str, taille_logique, "%u", *((unsigned int *) col->donnee[i]));
            break;
        case USHORT:
            snprintf(str, taille_logique, "%hu", *((unsigned short *) col->donnee[i]));
            break;
        case SHORT:
            snprintf(str, taille_logique, "%hd", *((short *) col->donnee[i]));
            break;
        case ULONG:
            snprintf(str, taille_logique, "%llu", *((unsigned long long int *) col->donnee[i]));
            break;
        case LONG:
            snprintf(str, taille_logique, "%lld", *((signed long long int *) col->donnee[i]));
            break;
        case UCHAR:
            snprintf(str, taille_logique, "%c", *((unsigned char *) col->donnee[i]));
            break;
        case CHAR:
            snprintf(str, taille_logique, "%c", *((signed char *) col->donnee[i]));
            break;
        case FLOAT:
            snprintf(str, taille_logique, "%f", *((float *) col->donnee[i]));
            break;
        case DOUBLE:
            snprintf(str, taille_logique, "%lf", *((double *) col->donnee[i]));
            break;
        case STRING:
            snprintf(str, taille_logique, "%s", *((char **) col->donnee[i]));
            break;
        case OBJECT: {
            Objet_value *valeur = (Objet_value *) col->donnee[i];
            print_object(valeur, i, str, taille_logique);
            break;
        }
        default:
            snprintf(str, taille_logique, "Type non géré");
            
            break;
    }
}
void print_col(Column* col){
    
        char str[64];
        for (unsigned int i = 0; i < col->taille_logique; i++) {
            print_value(col, i, str, sizeof(str));
            printf("[%u] %s\n", i, str);
        }
    }
void info_column(Column* col) {
    if (col == NULL) {
        printf("La colonne est NULL.\n");
        return;
    }
    
    printf("Titre: %s\n", col->titre);
    printf("Taille logique: %u\n", col->taille_logique);
    printf("Taille physique: %u\n", col->taille_physique);
    printf("Type de colonne: %d\n", col->column_type);
    printf("Valid index: %d\n", col->valid_index);
    printf("Sort direction: %d\n", col->sort_dir);
    printf("Index size: %u\n", col->index_size);
}
