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

    //ouverture du fichier txt
    pFile = fopen("fichierRepertoire.txt", "r");
    //verification si ouvert
    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }
    //rembobinage du fichier
    rewind(pFile);

    printf("Quelle personne chercher vous ? : ");
    char ch[255];
    int verif = 1;
    scanf("%s", ch);
    printf("%s\n", ch);

    //tant que le fichier n'est pas fini faire
    while (!feof(pFile)) {

        //recuperation de la ligne
        fgets(strNom, 255, pFile);

        //verifier jusqu'a que le mot soit fini
        for (i = 0; i < strlen(ch);i++) {
            if (ch[i] != strNom[6 + i]) {

                verif = 0;

            }
        }
        //si le mot correspond avec ce qui est proposé
        if (verif == 1) {

            printf("%s", strNom);
            //sortie de la boucle
            exit(0);

        }
        verif = 1;
        //fputs(strNom, stdout);
        i++;

    }
    //fermeture du fichier
    fclose(pFile);


    return 0;
}

