#ifndef PROJET_C_DATAFRAME_H
#define PROJET_C_DATAFRAME_H
#include "colonne.h"
typedef struct{
    Column**colonne;
    int nombre_colonne;
    int nombre_ligne;
}dataframe;
dataframe* creer_cdataframe(dataframe*df);
int ajouter_colonne(dataframe*df);
int ajouter_ligne(dataframe*df);
int remplir_datafarme(dataframe*df);

dataframe afficher_cdataframe(dataframe*df);




#endif
