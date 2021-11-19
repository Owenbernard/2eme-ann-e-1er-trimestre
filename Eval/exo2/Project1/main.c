//bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stockage.h"


void initStock(tStock* ptr_stock);

int main()
{

    tStock myStock;

    initStock(&myStock);

    FILE* pFile = NULL;
    //ouverture du fichier
    pFile = fopen("fichierRepertoire.txt", "a");

    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }

    char strTemp[255];

    //ecriture dans le fichier repertoire
    fprintf(pFile, "%d  |  ", myStock.n_id);

    strcpy(strTemp, myStock.str_nom);
    fprintf(pFile, "%s  |  ", strTemp);

    strcpy(strTemp, myStock.str_prenom);
    fprintf(pFile, "%s  |  ", strTemp);

    fprintf(pFile, "%d", myStock.n_age);
    fprintf(pFile, "%d  |  ", myStock.n_age);

    strcpy(strTemp, myStock.str_tel);
    fprintf(pFile, "%s  \n", strTemp);

    //fermeture du fichier
    fclose(pFile);

    int n_Id = 0;
    int n_ptVie = 0;
    char strNom[255];
    //ouverture du fichier
    pFile = fopen("fichierRepertoire.txt", "r");

    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }

    rewind(pFile);
    int n_cpt = 0;
    //tant que le fichier n'est pas fini
    while (!feof(pFile)) {

        fgets(strNom, 255, pFile);
        n_cpt++;
        fputs(strNom, stdout);


    }
    //fermeture du fichier
    fclose(pFile);

    //liberation du struct
    free(myStock.str_nom);
    return 0;
}

