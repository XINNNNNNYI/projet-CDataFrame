#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_colonne.h"

Column* create_column(Enum_Type type, char *column_name) {
    Column *col = (Column *) malloc(sizeof(Column));
    if (col == NULL)
        return NULL;

    col->column_name = column_name;
    col->column_type = type;
    col->size = 0;
    col->taille_physique = 0;
    col->donnee = NULL;
    col->index = NULL;
    col->valid_index = 0;
    col->sort_dir = 0;
    col->index_size = 0;
    return col;
}

int insert_value(Column *col, void *value) {
    if (col == NULL)
        return 0;

    if (col->size >= col->taille_physique) {
        unsigned int new_taille_physique = col->taille_physique + REALLOC_SIZE;
        Column_Type **new_donnee = (Column_Type **) realloc(col->donnee, new_taille_physique * sizeof(Column_Type *));
        if (new_donnee == NULL)
            return 0;
        col->donnee = new_donnee;
        col->taille_physique = new_taille_physique;

        unsigned long long int *new_index = (unsigned long long int *) realloc(col->index, new_taille_physique * sizeof(unsigned long long int));
        if (new_index == NULL && new_taille_physique > 0) {
            col->valid_index = -1;
        } else {
            col->index = new_index;
            col->index_size = new_taille_physique;
            col->valid_index = -1;
        }
    }

    if (value == NULL) {
        col->donnee[col->size] = NULL;
    } else {
        Column_Type *new_val = (Column_Type *) malloc(sizeof(Column_Type));
        if (new_val == NULL)
            return 0;

        switch (col->column_type) {
            case UNINT:
                new_val->uint_value = *(unsigned int *) value;
                break;
            case INT:
                new_val->int_value = *(int *) value;
                break;
            case CHAR:
                new_val->char_value = *(char *) value;
                break;
            case FLOAT:
                new_val->float_value = *(float *) value;
                break;
            case DOUBLE:
                new_val->double_value = *(double *) value;
                break;
            case STRING:
                if ((char *) value == NULL) {
                    new_val->string_value = NULL;
                } else {
                    unsigned int len = (unsigned int) strlen((char *) value);
                    new_val->string_value = (char *) malloc(len + 1);
                    if (new_val->string_value == NULL) {
                        free(new_val);
                        return 0;
                    }
                    strcpy(new_val->string_value, (char *) value);
                }
                break;
            case OBJECT:
                new_val->object_value = value;
                break;
            case NULLVAL:
            default:
                printf("Type de colonne non géré\n");
                free(new_val);
                return 0;
        }
        col->donnee[col->size] = new_val;
    }

    if (col->index != NULL)
        col->index[col->size] = col->size;

    col->size++;
    col->valid_index = -1;

    return 1;
}



