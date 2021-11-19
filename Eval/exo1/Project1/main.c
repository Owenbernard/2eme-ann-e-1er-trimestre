
//bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//création d'un struct pour récupérer le text
typedef struct tText {
    char* str_nom;
}tText;

//initier le struc
void initText(tText* ptr_myHero);


int main()
{

    tText myHero;

    //fonction init
    initText(&myHero);

    FILE* pFile = NULL;

    char strNom[255];

    // ouvrir le fichier de texte
    pFile = fopen("Base.txt", "r");
    //verifier si il y a pas d'erreur
    if (pFile == NULL) {
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }
    //rembobiner le fichier
    rewind(pFile);

    int ligne = 0;
    int n_cpt = 0;

    //tant que le fichier n'est pas fini faire
    while (!feof(pFile)) {

        //on recupere 80 caractère
        fgets(strNom, 80, pFile);
        n_cpt++;
        if (n_cpt = 80) {

            // affichage du nombre de ligne
            printf("\n %d : ",ligne);
            ligne++;
        }
        //affichage du texte
        fputs(strNom, stdout);


    }
    //fermeture du fichier
    fclose(pFile);
    //on libère de la memoire en libérant la var struct
    free(myHero.str_nom);

    return 0;
}


void initText(tText* ptr_myHero) {


    ptr_myHero->str_nom = (char*)malloc(255 * sizeof(char));

    if (ptr_myHero->str_nom != NULL) {
        strcpy(ptr_myHero->str_nom, "");
    }


}