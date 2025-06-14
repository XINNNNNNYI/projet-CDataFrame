//
// Created by MOUMSIK on 14/06/2025.
//

#ifndef PROJET_C_NEW_COLONNE_H
#define PROJET_C_NEW_COLONNE_H

#include <stdio.h>
#include <stdlib.h>   // Pour malloc/free
#include <string.h>   // Pour strdup


#define REALLOC_SIZE 256

typedef enum {
    NULLVAL = 1,
    UINT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    USHORT,
    OBJECT,
    SHORT,
    ULONG,
    LONG,
    UCHAR,
   


} Enum_Type;


typedef union {
    unsigned int uint_value;
    signed int int_value;
    unsigned short ushort_value;
    signed short short_value;
    unsigned long long int ulong_int;
    signed long long int long_int;
    unsigned char uchar_value;
    signed char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* object_value;
} Column_Type;
typedef enum{
    OBJECT_UNINT,
    OBJECT_INT,
    OBJECT_CHAR,
    OBJECT_FLOAT,
    OBJECT_DOUBLE,
    OBJECT_STRING,

}Enum_Object;
typedef struct{
    Enum_Object type;
    Column_Type value;


}Objet_value;

typedef struct  {
    char* titre;
    unsigned int taille_logique;
    unsigned int taille_physique;
    Enum_Type column_type;
    Column_Type** donnee;
    unsigned long long int* index;
    char valid_index;
    char sort_dir;
    unsigned int index_size;
} Column;

// Fonctions associées
Column* create_column(Enum_Type type, char* titre);
int insert_value(Column* col, void* value);
void delete_column(Column* col);
void print_object(Objet_value*ob, char* str, unsigned int taille_logique );
void print_value(Column* col, unsigned long long int i, char* str, unsigned int taille_logique);
void print_col(Column* col);
void info_column(Column* col);

#endif // PROJET_C_NEW_COLONNE_H
