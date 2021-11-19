#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Pointeurs de fcts
typedef struct tHero {

    int n_id;
    char* str_nom;
    int n_ptVie;

}tHero;




int saisie(char cSaisie[255], int nTaille);
void initHero(tHero* ptr_myHero);
void saveHero(tHero* myHero);
void loadHero(tHero* myHero);




int main()
{



    //Fichier txt (sprintf)

   /* tHero myHero;
    initHero(&myHero);
    FILE * pFile=NULL;
   //Ecriture
   pFile = fopen ("myfile.txt","a");
    if(pFile==NULL){
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }
    char strTemp[255];
    int n_temp=sprintf (strTemp, "Id : %d; Nom : %s; Vie : %d\n", myHero.n_id, myHero.str_nom, myHero.n_ptVie);
    fputs(strTemp,pFile);
    fclose(pFile);
    //Lecture
    pFile = fopen ("myfile.txt","r");
    if(pFile==NULL){
        perror("Erreur ouverture/ecriture fichier\n");
        system("pause");
        exit(1);
    }
    rewind (pFile);
   do{
        fgets(strTemp,255,pFile);
        printf("%s",strTemp);
        strcpy(strTemp,"\0");
    }while(!feof(pFile));
    char c;
    while(!feof(pFile)){
      c=fgetc(pFile);
      fputc(c,stdout);
    }
    while (fgets(strTemp, 255, pFile) != NULL) // On lit les chaines de caracteres tant que la reference est differente de NULL
    {
            printf("%s", strTemp); // On affiche la chaine que nous venons de lire
    }
    fclose(pFile);
    free(myHero.str_nom);*/


    //Fichier binaire
    tHero* myHero;

    myHero = malloc(sizeof(tHero));

    int size = sizeof(myHero);



    saveHero(myHero);
    loadHero(myHero);

    free(myHero);






    return 0;
}


void somme(int n_a, int n_b, int* ptrRes) {

    *ptrRes = n_a + n_b;

}


void initHero(tHero* ptr_myHero) {

    ptr_myHero->n_id = 1;

    ptr_myHero->str_nom = (char*)malloc(255 * sizeof(char));

    if (ptr_myHero->str_nom != NULL) {

        strcpy(ptr_myHero->str_nom, "Lehmann");
    }

    ptr_myHero->n_ptVie = 100;

}



void saveHero(tHero* myHero) {

    FILE* pFile;
    int i;

    myHero->str_nom = (char*)malloc(255 * sizeof(char));


    myHero->str_nom = "Lehmann";
    myHero->n_ptVie = 100;

    //Ecriture fichier binaire
    pFile = fopen("Base.txt", "a");


    for (i = 0;i < 3;i++) {
        myHero->n_id = i + 1;
        fwrite(myHero, sizeof(tHero), sizeof(myHero), pFile);
    }



    fclose(pFile);


}


void loadHero(tHero* myHero) {

    FILE* pFile;

    long lSize;
    tHero* buffer;
    size_t result;


    pFile = fopen("Base.txt", "r");

    if (pFile == NULL) { fputs("File error", stderr); exit(1); }

    // obtain file size:
    fseek(pFile, sizeof(tHero), SEEK_END);//position of cursor in file <At EOF>
    lSize = ftell(pFile); //Get current position in stream (octets)
    rewind(pFile);//Set position of stream to the beginning (function )

     // allocate memory to contain the whole file:

    buffer = malloc(lSize);
    //buffer=malloc(sizeof(cid)*lSize)

    if (buffer == NULL) { fputs("Memory error", stderr); exit(2); }

    //Lecture 1 stucture fichier binaire
    //result = fread (buffer,1,lSize,pFile);

    // copy the file into the buffer:

    while ((result = fread(buffer, sizeof(tHero), sizeof(myHero), pFile))) {

        //result=
        if (result != sizeof(myHero)) { fputs("Reading error", stderr); exit(3); }

        printf("%d\n", buffer->n_id);
        printf("%s\n", buffer->str_nom);
        printf("%d\n", buffer->n_ptVie);

        printf("\n");


    }


    // terminate
    fclose(pFile);

    free(buffer);





}

int saisie(char cSaisie[100], int nTaille) {

    char* positionEntree = NULL;


    if (fgets(cSaisie, nTaille, stdin) != NULL) {

        positionEntree = strchr(cSaisie, '\n');

        positionEntree != NULL ? *positionEntree = '\0' : fflush(stdin);

        return 1;
    }
    else {

        fflush(stdin);
        return 0;

    }


}
