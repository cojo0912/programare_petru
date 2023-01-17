#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DICTIONARY_SIZE 10

typedef struct _word {
    char *word;
    char *definition;
    int lenght;
} word;

//comentariu penrteu mai tarziu
/*
    FILE* f = fopen("E:\\Proiecte si teme\\GIT_REPOS\\programare_petru\\9_17_IAN_2023\\ex\\words.txt", "r");
    if(f == NULL)
    {
        printf("nu a mers\n");
        return 0;
    }

    char c[255];
    char d[255];
    while(fscanf(f, "%s ", c)>0)
    {
        fgets(d, 255, f);
        printf("%s = %s\n", c ,d);
    }
*/

/*
ENUNT:
    1 - trebuie sa cream dictionarul 
    2 - trebuie sa cream dictionarul  iar raspunsul sa il returnam (noul dictionar sa fie returnat)
    3 - ca terbuii sa adaugam 
    4 - va trebuii sa adaugam citind de la tastura
    5 - va trebuii sa adaugam citind din fisier
    6 - eliberezi memoria pentru dictionar
    8 - definitia unui cuvant
    9 - vreau sa imi gasesti un apropo la un cuvant
*/

void creare1(word ** dictionar, int* size)
{
    (*size) = DICTIONARY_SIZE;
    (*dictionar) = (word *)malloc(sizeof(word)*(*size));
    for(int i=0; i<*size; i++)
    {
        (*dictionar)[i].word = NULL;
        (*dictionar)[i].definition = NULL;
        (*dictionar)[i].lenght = 0;
    }
}

word* creare2(word *dictionar, int *size)
{
    (*size) = DICTIONARY_SIZE;
    dictionar = (word*) malloc(sizeof(word)*(*size));
    for(int i=0; i<*size; i++)
    {
        (dictionar)[i].word = NULL;
        (dictionar)[i].definition = NULL;
        (dictionar)[i].lenght = 0;
    }
    return dictionar;
}

void creare3(word * dictionar[], int* size)
{
    (*size) = DICTIONARY_SIZE;
    (*dictionar) = (word *)malloc(sizeof(word)*(*size));
    for(int i=0; i<*size; i++)
    {
        (*dictionar)[i].word = NULL;
        (*dictionar)[i].definition = NULL;
        (*dictionar)[i].lenght = 0;
    }
}

void adauga(word *dictionar, int size, char *cuv, char *def)
{
    int contor = 0;
    for(int i=0; i<size; i++)
    {
        if(dictionar[i].word == NULL)
        {
            dictionar[i].word = (char*)malloc(sizeof(char)*(strlen(cuv)+1));
            dictionar[i].definition = (char*)malloc(sizeof(char)*(strlen(def)+1));

            strcpy(dictionar[i].word, cuv);
            strcpy(dictionar[i].definition, def);
            dictionar[i].lenght = strlen(cuv);
            contor++;
            break;
        }
    }
    if(contor == 0)
        printf("dinctionarul este full\n");
}

void print(word *dictionar, int size)
{
    for(int i=0; i<size; i++)
    {
        if(dictionar[i].word!=NULL)
        {
            printf("%s [%d] = %s\n", dictionar[i].word, dictionar[i].lenght, dictionar[i].definition);
        }
    }
}

void citireFisier(word *dictionar, int size)
{
    FILE* f = fopen("E:\\Proiecte si teme\\GIT_REPOS\\programare_petru\\9_17_IAN_2023\\ex\\words.txt", "r");
    if(f == NULL)
    {
        printf("nu a mers\n");
        return;
    }

    char c[255];
    char d[255];
    while(fscanf(f, "%s ", c)>0)
    {
        fgets(d, 255, f);
        c[strlen(c)-1] = '\0';
        d[strlen(d)-1] = '\0';
        adauga(dictionar, size, c, d);
    }
}

word* eliberare(word *dictionar, int *size)
{ 
    if(dictionar == NULL)
        return dictionar;

    for(int i=0; i<*size; i++)
    {
        if(dictionar[i].word!=NULL)
        {
            free(dictionar[i].word);
            free(dictionar[i].definition);
            (dictionar)[i].word = NULL;
            (dictionar)[i].definition = NULL;
            (dictionar)[i].lenght = 0;
        }
    }
    (*size) = 0;
    free(dictionar);
    dictionar = NULL;
    return dictionar;
}

void cautare_definitie(word *dictionar, int size, char *de_cautat)
{   
    for(int i=0; i<size; i++)
    {
        if(dictionar[i].word!=NULL)
        {
            if(strcmp(dictionar[i].word, de_cautat)==0)
                printf("%s = %s\n", dictionar[i].word, dictionar[i].definition);
        }
    }
}

void cautare_apropos(word *dictionar, int size, char *de_cautat)
{
    for(int i=0; i<size; i++)
    {
        if(dictionar[i].word!=NULL)
        {
            if(strstr(dictionar[i].definition, de_cautat)!=NULL)
            {
                printf("%s = %s\n", dictionar[i].word, dictionar[i].definition);
                break;
            }
        }
    }
}

//1 daca c2 > c1
int comparare(char *c1, char *d1, char *c2, char *d2)
{
    if(c1 == NULL && c2 == NULL)
        return 0;
    
    if(c1 != NULL && c2 == NULL)
        return -1;

    if(c1 == NULL && c2 != NULL)
        return 1;

    if(strcmp(c1, c2)==0)
        return strcmp(d1, d2);
    else 
        return strcmp(c1, c2);
}

void ordonare_alfabetica(word *dictionar, int size)
{
    int contor = 1;
    while(contor > 0)
    {
        contor = 0;
        for(int i = 0; i<size-1; i++)
        {
            if(comparare(dictionar[i].word, dictionar[i].definition, dictionar[i+1].word, dictionar[i].definition) > 0)
            {
                char * aux;
                aux = dictionar[i].word;
                dictionar[i].word = dictionar[i+1].word;
                dictionar[i+1].word = aux;

                aux = dictionar[i].definition;
                dictionar[i].definition = dictionar[i+1].definition;
                dictionar[i+1].definition = aux;

                int aux2;
                aux2 = dictionar[i].lenght;
                dictionar[i].lenght = dictionar[i+1].lenght;
                dictionar[i+1].lenght = aux2;
                contor++;
            }
        }
    }
}

int main(void)
{
    word *dictionar = NULL;
    int size = 0;

    //printf("%d\n", strlen("a\nb\n"));

    creare3(&dictionar, &size);

    adauga(dictionar, size, "casa", "cladire in care locuieste");
    adauga(dictionar, size, "portcola", "fruct popular de craciun");
    adauga(dictionar, size, "economie", "ceva ce romania nu are");
    adauga(dictionar, size, "patriotism", "ce simt romanii");
    print(dictionar, size);

    citireFisier(dictionar, size);
    print(dictionar, size);

    cautare_definitie(dictionar, size, "portcola");
    cautare_apropos(dictionar, size, "rom");

    ordonare_alfabetica(dictionar, size);
    print(dictionar, size);
    //citim un cuv si definitie si le adaugam
    /*
    char cuv[255];
    char def[512];
    printf("Cuv? \n");
    scanf("%s", cuv);
    
    printf("Def? \n");
    
    fgets(def, 512, stdin);
    fgets(def, 512, stdin);

    adauga(dictionar, size, cuv, def);
    */

   /*
   TEMA:
    - sa te uiti in trecut peste tot ce am lucrat si sa ma intreb nu intelegi
    - la ex asta sa imi faci functie care daca gaseste sa il stearga (+eliberare memorie)
    - uite-te peste matrici fa un execitiu care citeste 2 matrici de 3 pe 3 si le inmulteste (aloca memorie dinamic pentru matrici)
        -functii care aloca matricile
        -vezi unde aloci memorie pentru rezultat
        -dupa ce ai facut cu 3 pe 3 generalizezi la n pe n
        -dupa care faci si scadere si adunare
        -la 3 pe 3 faci si determinantul
   */

    //printf
    dictionar = eliberare(dictionar, &size);
    return 0;
}
