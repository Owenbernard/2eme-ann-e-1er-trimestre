//bibliothèque
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stockage.h"


void initStock(tStock* ptr_stock) {
    ptr_stock->n_id = 1;

    char ch[255] = "";
    //recupere le nom voulu
    printf("Inserer le nom de la personne : ");
    scanf("%s", ch);
    ptr_stock->str_nom = (char*)malloc(255 * sizeof(char));
    if (ptr_stock->str_nom != NULL) {
        strcpy(ptr_stock->str_nom, ch);
    }
    //recupere le prenom voulu
    printf("Inserer le prenom de la personne : ");
    scanf("%s", ch);
    ptr_stock->str_prenom = (char*)malloc(255 * sizeof(char));
    if (ptr_stock->str_prenom != NULL) {
        strcpy(ptr_stock->str_prenom, ch);
    }
    //recupere le age voulu
    printf("Inserer l age de la personne : ");
    scanf("%d", &ptr_stock->n_age);

    //recupere le n de tel voulu
    printf("Inserer le tel de la personne : ");
    scanf("%s", ch);
    ptr_stock->str_tel = (char*)malloc(255 * sizeof(char));
    if (ptr_stock->str_tel != NULL) {
        strcpy(ptr_stock->str_tel, ch);
    }


}