#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DB_SZIE 10

typedef struct _product_t {
    char *product;
    float price;
} product_t;


product_t * newDatabase (product_t *database, int *dbSize, int newSize)
{
    database = (product_t *)malloc(sizeof(product_t)*newSize);
    *dbSize = newSize;

    for(int i=0; i<(*dbSize); i++)
    {
        database[i].product = NULL;
        database[i].price = -1;
    }
    return database;
}

void newDatabase2(product_t **database, int *dbSize, int newSize)
{
    (*database) = (product_t *)malloc(sizeof(product_t)*newSize);
    *dbSize = newSize;
    for(int i=0; i<(*dbSize); i++)
    {
        (*database)[i].product = NULL;
        (*database)[i].price = -1;
    }
}
int compara(product_t p1, product_t p2)
{
    //functia returneaza 0 daca sunt egale, >0 daca p1>p2, <0 daca p1<p2
    if(p1.product == NULL && p2.product == NULL)
        return 0;

    if(p1.product == NULL && p2.product != NULL)
        return 1;

    if(p1.product != NULL && p2.product == NULL)
        return -1;

    return strcmp(p1.product, p2.product);
}

int compara2(product_t p1, product_t p2)
{
    //functia returneaza 0 daca sunt egale, >0 daca p1>p2, <0 daca p1<p2
    if(p1.product == NULL && p2.product == NULL)
        return 0;

    if(p1.product == NULL && p2.product != NULL)
        return 1;

    if(p1.product != NULL && p2.product == NULL)
        return -1;

    if(p1.price == p2.price)
        return strcmp(p1.product, p2.product);

    if(p1.price > p2.price)
        return 1;

    if(p1.price < p2.price)
        return -1;
}

void sortAlfabetic(product_t *database, int dbSize)
{
    int contor = 1;
    while(contor > 0)
    {
        contor = 0;
        for(int i =0; i<dbSize-1; i++)
        {
            if(compara(database[i], database[i+1])>0)
            {
                char * p_aux = database[i].product;
                database[i].product = database[i+1].product;
                database[i+1].product = p_aux;

                float price_aux = database[i].price;
                database[i].price = database[i+1].price;
                database[i+1].price = price_aux;

                contor ++;
            }
        }
    }
}

void sortDupaPret(product_t *database, int dbSize)
{
    int contor = 1;
    while(contor > 0)
    {
        contor = 0;
        for(int i =0; i<dbSize-1; i++)
        {
            if(compara2(database[i], database[i+1])>0)
            {
                char * p_aux = database[i].product;
                database[i].product = database[i+1].product;
                database[i+1].product = p_aux;

                float price_aux = database[i].price;
                database[i].price = database[i+1].price;
                database[i+1].price = price_aux;

                contor ++;
            }
        }
    }
}

void printDatabase (product_t *database, int dbSize)
{
    for(int i=0; i<dbSize; i++)
    {
        if(database[i].product != NULL)
        {
            //verifica folderul poentru prima meditaatie fisierul despre printf
            printf("product %10s costs %07.2f\n", database[i].product, database[i].price);
        }else
        {
            printf("product is NULL\n");
        }
    }
}

void addProduct (product_t *database, int dbSize, char *product, float price)
{
    //prima oara adaugam si dupa sortam
    int counter = 0;
    for(int i=0; i<dbSize; i++)
    {
        if(database[i].product == NULL)
        {
            database[i].product = (char *)malloc((strlen(product)+1) * sizeof(char));
            strcpy(database[i].product, product);
            database[i].price = price;
            counter ++;
            break;
        }
    }

    if(counter == 0)
    {
        printf("Database is full\n");
    }else
    {
        sortAlfabetic(database, dbSize);
    }
}

void addProduct2 (product_t *database, int dbSize, char *product, float price)
{
    //adaugam direct la pozitia corecta
}

void readFile (product_t *database, int dbSize, char *fileName)
{
    //E:\Proiecte si teme\GIT_REPOS\programare_petru\8_15_IAN_2022\ex\produse.txt
    //https://cplusplus.com/reference/cstdio/fopen/
    FILE * file;
    file = fopen(fileName, "r");

    if(file == NULL)
    {
        printf("Fisierul nu a putut fi deschis!\n");
        return;
    }

    //CITIRE LINIE CU LINIE
    /*char linie[255];
    while(fgets(linie, 255, file)!=NULL)
    {
        printf("Citit linie: %s", linie);
    }*/
    char aux_produs[255];
    float aux_price;
    while(fscanf(file, "%s %f", aux_produs, &aux_price) == 2)
    {
        //printf("citit: %s %f\n", aux_produs, aux_price);
        addProduct(database, dbSize, aux_produs, aux_price);
    }
}

//https://www.geeksforgeeks.org/binary-search/

product_t * findProduct (product_t *database, int dbSize, char *product, int lower, int upper)
{
    if(lower > upper)
        return NULL;

    int mid = (lower + upper) / 2;
    if(strcmp(database[mid].product, product) == 0)
        return &database[mid];
    else if(strcmp(database[mid].product, product)<0)
        return findProduct(database, dbSize, product, mid+1, upper);
    else
        return findProduct(database, dbSize, product, lower, mid-1);
}

int main(void)
{
    product_t *database = NULL;
    int dbSize = 0;


    database = newDatabase(database, &dbSize, DB_SZIE);
    printf("Valoare pointer %p\n", database);

    addProduct(database, dbSize, "produs_d", 1.2);
    addProduct(database, dbSize, "produs_c", 1.3);
    printDatabase(database, dbSize);
    readFile(database, dbSize, "E:\\Proiecte si teme\\GIT_REPOS\\programare_petru\\8_15_IAN_2022\\ex\\produse.txt");
    printf("--------------------------------\n");
    printDatabase(database, dbSize);

    //sortDupaPret(database, dbSize);
    printf("--------------------------------\n");
    printDatabase(database, dbSize);

    product_t * cautare = findProduct(database, dbSize, "crisps", 0, dbSize-1);
    if(cautare == NULL)
        printf("Produsul NU a fost gasit");
    else
        printf("Produsul a fost gasit: %s %f", cautare->product, cautare->price);
    return 0;
}
