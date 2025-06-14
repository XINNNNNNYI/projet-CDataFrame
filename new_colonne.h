#ifndef PROJET_C_NEW_COLONNE_H
#define PROJET_C_NEW_COLONNE_H
#include<stdio.h>

#define REALLOC_SIZE 256

typedef enum {
    NULLVAL = 1,
    UNINT,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    STRING,
    OBJECT
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
    char *string_value;
    void *object_value;
} Column_Type;

typedef struct Column {
    char *column_name;
    unsigned int size;
    unsigned int taille_physique;
    Enum_Type column_type;
    Column_Type **donnee; // tableau de pointeurs vers l'union Column_Type

    unsigned long long int *index;
    char valid_index;
    char sort_dir;
    unsigned int index_size;
} Column;

Column* create_column(Enum_Type type, char *column_name);
int insert_value(Column *col, void *value);

#endif
void delete_column(Column*col);
void print_value(Column*col, unsigned long long int i, char*str, int size);
void print_col(Column*col);
void info_column(Column*col);


#endif //PROJET_C_NEW_COLONNE_H
