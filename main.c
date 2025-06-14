#include <stdio.h>
#include "new_colonne.h"


int main() {
    
    char str[20]; 
    int N=20; // un peu plus grand pour être sûr

    char* caca = "caca";  // titre de la colonne, chaîne constante

    Column* mycol = create_column(INT, caca);

    int a = 52, b = 44, c = 15, d = 18;
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &c);
    insert_value(mycol, &d);

    print_value(mycol, 2, str, N);
    printf("%s\n", str);

    delete_column(mycol);

    return 0;
}
