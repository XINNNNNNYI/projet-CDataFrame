#include <stdio.h>
#include <stdlib.h>
#include "dataframe.h"
#include "colonne.h"
dataframe* creer_cdataframe(dataframe*df){
    dataframe*df=malloc(sizeof(dataframe));
    if (df==NULL)
        return NULL;
    df->colonne=NULL;
    df->nombre_colonne=0;
    df->nombre_ligne=0;


return df;}
void remplissage_dur(dataframe*df){
    if (df==NULL)
        return 0;
    char*titre=NULL;
    printf("Saisir le nom de la colonne");
    scanf("%s", titre);
    Column *col=create_column(titre);
    if(col==NULL)
        return 0;
    for (int i=0; i<df->nombre_ligne; i++){
        insert_value(col,0);

    }


}
int ajouter_colonne(dataframe*df, char*titre){
    if (df==NULL)
        return 0;
    char*titre=NULL;
    printf("Saisir le nom de la colonne");
    scanf("%s", titre)
    Column*create_column(titre);
    if(col==NULL)
        return 0;
    for(int i=0; i<df->nombre_ligne; i++){

    }
}
