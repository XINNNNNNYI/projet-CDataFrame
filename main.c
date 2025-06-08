#include "colonne.h"
int main() {
    COLUMN*col = create_column("Colonne");
    print_col(col);
    for (int i = 0;i<258;i++) {
        (insert_value(col,i));
    }
    print_col(col);

    delete_column(col);

    col = create_column("Colonnev2");
    for (int i = 0; i < 5; i++) {
        (insert_value(col,i));
    }
    print_col(col);

    return 0;
}
