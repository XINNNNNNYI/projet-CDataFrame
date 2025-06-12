#include <stdio.h>
#include <stdlib.h>

typedef struct list_chainees{
    char*value;
    struct list_chainees* next;
}LC;

LC *lstnew(char*content) {
    LC *new =malloc(sizeof(LC));
    new->value = content;
    new->next = NULL;
    return new;
}

void lst_addback(LC**list,LC* new) {
    LC *p = *list;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;
}

void affiche_lst(LC *lst) {
    LC* p = lst;
    while (p != NULL) {
        printf("%s\n", p->value);
        p = p->next;
    }
}
