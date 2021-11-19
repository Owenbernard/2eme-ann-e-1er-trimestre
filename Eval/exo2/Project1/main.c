#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stockage.h"


void somme(int n_a, int n_b, int* ptrRes);

void initStock(tStock* ptr_stock);

int main()
{

    tStock myStock;

    initStock(&myStock);

    FILE* pFile = NULL;

    pFile = fopen("fichierRepertoire.txt", "a");

    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }

    char strTemp[255];


    fprintf(pFile, "%d  |  ", myStock.n_id);

    strcpy(strTemp, myStock.str_nom);
    fprintf(pFile, "%s  |  ", strTemp);

    strcpy(strTemp, myStock.str_prenom);
    fprintf(pFile, "%s  |  ", strTemp);

    fprintf(pFile, "%d", myStock.n_age);
    fprintf(pFile, "%d  |  ", myStock.n_age);

    strcpy(strTemp, myStock.str_tel);
    fprintf(pFile, "%s  \n", strTemp);

    fclose(pFile);

    int n_Id = 0;
    int n_ptVie = 0;
    char strNom[255];

    pFile = fopen("fichierRepertoire.txt", "r");

    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }

    rewind(pFile);
    int n_cpt = 0;

    while (!feof(pFile)) {

        fgets(strNom, 255, pFile);
        n_cpt++;
        fputs(strNom, stdout);


    }

    fclose(pFile);

    free(myStock.str_nom);
    return 0;
}

