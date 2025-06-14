#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_colonne.h"

Column* create_column(Enum_Type type, char* column_name) {
    Column* col = (Column*) malloc(sizeof(Column));
    if (col == NULL)
        return NULL;

    col->column_name = column_name;
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

int insert_value(Column* col, void* value) {
    if (col == NULL || value == NULL)
        return 0;

    if (col->taille_physique == 0) {
        col->donnee = malloc(REALLOC_SIZE * sizeof(Column_Type*));
        if (col->donnee == NULL)
            return 0;
        col->taille_physique = REALLOC_SIZE;
    } else if (col->taille_logique >= col->taille_physique) {
        Column_Type** data = realloc(col->donnee, (col->taille_physique + REALLOC_SIZE) * sizeof(Column_Type*));
        if (data == NULL)
            return 0;
        col->donnee = data;
        col->taille_physique += REALLOC_SIZE;
    }

    Column_Type* new_val = (Column_Type*) malloc(sizeof(Column_Type));
    if (new_val == NULL)
        return 0;

    switch (col->column_type) {
        case UNINT:
            new_val->uint_value = *(unsigned int*) value;
            break;
        case INT:
            new_val->int_value = *(int*) value;
            break;
        case CHAR:
            new_val->char_value = *(char*) value;
            break;
        case FLOAT:
            new_val->float_value = *(float*) value;
            break;
        case DOUBLE:
            new_val->double_value = *(double*) value;
            break;
        case STRING:
            if (*(char**)value == NULL) {
                new_val->string_value = NULL;
            } else {
                size_t len = strlen(*(char**)value);
                new_val->string_value = malloc(len + 1);
                if (new_val->string_value == NULL) {
                    free(new_val);
                    return 0;
                }
                strcpy(new_val->string_value, *(char**)value);
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

    col->donnee[col->taille_logique] = new_val;

    if (col->index != NULL)
        col->index[col->taille_logique] = col->taille_logique;

    col->taille_logique++;
    col->valid_index = -1;

    return 1;
}
