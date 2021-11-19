//bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stockage.h"


int main()
{

    tStock myStock;

    FILE* pFile = NULL;

    int n_Id = 0;
    int n_ptVie = 0;
    char strNom[255];
    int i = 0;
    //ouverture du fichier
    pFile = fopen("fichierRepertoire.txt", "r");
    //on verifie que le fichier souvre bien
    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }
    //on rembobine le fichier
    rewind(pFile);

    char ID[255];

    printf("Inserer l ID de la personne : ");
    scanf("%c", ID);

    //faire une boucle tant que ID est different de la ligne
    while (!feof(pFile)) {

        fgets(strNom, 255, pFile);
        if (strNom[0] == ID[0]) {

            printf("%s", strNom);
            exit(0);

        }
    }
    //fermeture du fichier
    fclose(pFile);

    return 0;
}

