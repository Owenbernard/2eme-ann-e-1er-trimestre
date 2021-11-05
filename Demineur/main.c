#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAILLEX 9
#define TAILLEY 9
#define MINE 10

void init_Tab(int Tab[TAILLEX][TAILLEY]);
void init_Tab2(int TabAnswer[TAILLEX][TAILLEY]);

void jeu(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]);
void crea_Tab(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]);
void check_Tab(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]);

void affichage_Tab(int Tab[TAILLEX][TAILLEY]);
void affichage_Tab2(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]);

int main()
{

    int i,j,repX,repY;
    struct TabGrill {
        int conteneur;
    };
    struct TabGrill Tab[TAILLEX][TAILLEY];
    struct TabGrill2 {
        int conteneur2;
    };
    struct TabGrill2 TabAnswer[TAILLEX][TAILLEY];


    //creation tab
    init_Tab(Tab);
    init_Tab2(TabAnswer);
    crea_Tab(Tab,TabAnswer);
    check_Tab(Tab,TabAnswer);

    //while
    jeu(Tab,TabAnswer);

    return 0;
}

void jeu(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]) {

    int vie = 2;
    int i,j;
    do {

        i = 0;
        j = 0;

        affichage_Tab2(Tab,TabAnswer);
        //affichage_Tab2(Tab, TabAnswer);
        //printf("%d",Tab[-1][8]);
        printf("Veuillez inserez la coordonee X : ");
        while (i>9||i<1){
            scanf("%d", &i);
        }
        i--;
        printf("\nVeuillez inserez la coordonee Y : ");
        while (j>9||j<1){
            scanf("%d", &j);
        }
        j--;

        int affichageLettre = Tab[j][i];
        int affichageValid = TabAnswer[j][i];

        if (affichageValid == 0) {
            //printf("valide av : %d \n",affichageValid);
            affichageValid = 1;
            //printf("valide ap : %d \n",affichageValid);
            TabAnswer[j][i] = affichageValid;

            if (affichageLettre == 9) {
                vie = 0;
                affichage_Tab(Tab);
            }
        }

    }while (vie != 0);

}



void init_Tab(int Tab[TAILLEX][TAILLEY]) {

    int i,j;
    //init tableaux
    for(i=0;i<TAILLEX;i++){
        for(j=0;j<TAILLEY;j++){
            Tab[i][j]=0;
        }
    }
}
void init_Tab2(int TabAnswer[TAILLEX][TAILLEY]) {

    int i,j;
    //init tableaux
    for(i=0;i<TAILLEX;i++){
        for(j=0;j<TAILLEY;j++){
            TabAnswer[i][j]=0;
        }
    }
}

int rdtsc() {
    __asm__ __volatile__("rdtsc");
}

//       Set up tableau de reponse

void crea_Tab(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]){

    int i,j,x,y,NbrRandom;

    // set random mine
    int mine = 0;
    do {
        for(i=0;i<TAILLEX;i++){
            for(j=0;j<TAILLEY;j++){

                srand(rdtsc());
                if (mine<MINE) {
                    NbrRandom= rand()%15;
                    if (NbrRandom!= 9) {
                        NbrRandom = 0;
                    }else{
                        if (Tab[i][j]!=9) {

                            Tab[i][j] = 9;
                            mine++;
                        }
                    }
                }
            }
        }
    } while (mine<MINE) ;

    //fin set random mine

    //pour enlever les objet a l'exterieur du tableaux

    for(i=-1;i<TAILLEX+1;i++) {
        Tab[i][-1] = 0;
        Tab[i][TAILLEY+1] = 0;
    }
    for(j=-1;j<TAILLEY+1;j++) {
        Tab[-1][j] = 0;
        Tab[TAILLEX+1][j] = 0;
    }
    // fin enlever les objet...

}

void check_Tab(int Tab[TAILLEX][TAILLEY], int TabAnswer[TAILLEX][TAILLEY]){
    int i,j;

    // set nbr de mine autour
    for(i=0;i<TAILLEX;i++) {
        for(j=0;j<TAILLEY;j++){
            if (Tab[i][j] != 9) {

                if (Tab[i-1][j] == 9) {Tab[i][j]++;}
                if (Tab[i-1][j+1] == 9) {Tab[i][j]++;}
                if (Tab[i-1][j-1] == 9) {Tab[i][j]++;}

                if (Tab[i+1][j] == 9) {Tab[i][j]++;}
                if (Tab[i+1][j+1] == 9) {Tab[i][j]++;}
                if (Tab[i+1][j-1] == 9) {Tab[i][j]++;}

                if (Tab[i][j+1] == 9) {Tab[i][j]++;}
                if (Tab[i][j-1] == 9) {Tab[i][j]++;}
            }
        }
    }

    //fin set nbr mine
}

void affichage_Tab(int Tab[TAILLEX][TAILLEY]){
    int i,j;
    printf("    ");
    for(i=0;i<TAILLEX;i++){
            printf("  %d ",i+1);
    }
    printf(" :  X  \n      - - - - - - - - - - - - - - - - - \n");

    for(i=0;i<TAILLEX;i++){
        printf(" %d | ",i+1);
        for(j=0;j<TAILLEY;j++){
            printf(" %d |",Tab[i][j]);
        }
        printf("  \n    ");
        for(j=0;j<TAILLEY;j++){
            printf("  - ");
        }
        printf("\n");
    }
    printf(" Y \n");
}

void affichage_Tab2(int Tab[TAILLEX][TAILLEY],int TabAnswer[TAILLEX][TAILLEY]){
    int i,j;
    printf("meh\n    ");
    for(i=0;i<TAILLEX;i++){
            printf("  %d ",i+1);
    }
    printf(" :  X  \n      - - - - - - - - - - - - - - - - - \n");

    for(i=0;i<TAILLEX;i++){
        printf(" %d | ",i+1);
        for(j=0;j<TAILLEY;j++){

            if (TabAnswer[i][j] == 1) {

                printf(" %d |",Tab[i][j]);

            }else{

                printf(" / |");

            }
        }
        printf("  \n    ");
        for(j=0;j<TAILLEY;j++){
            printf("  - ");
        }
        printf("\n");
    }
    printf(" Y \n");
}

// fin set up de reponse
