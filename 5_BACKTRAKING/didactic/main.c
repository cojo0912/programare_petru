#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMAR_EL 3

//https://www.geeksforgeeks.org/introduction-to-backtracking-data-structure-and-algorithm-tutorials/

//generarea tuturor numerelor de n cifre
void n5(int pas, int v[], int *numar_solutii)
{
    if(pas == NUMAR_EL)
    {
        (*numar_solutii)++;
        printf("Solutie %5d: ",*numar_solutii);
        for(int i=0; i<NUMAR_EL; i++)
            printf("%d", v[i]); 
        printf("\n");
        getc(stdin);        
        return;
    }
    for(int i=0; i<=9; i++)
    {
        if(pas == 0 && i==0)
            i++;
        v[pas] = i;

        printf("\e[1;1H\e[2J");
        for(int i=0; i<pas; i++)
            printf("%d ", v[i]); 
        getc(stdin);

        n5(pas+1, v, numar_solutii);
    }
}

//generarea tuturor numerelor de n cifre distrincte
void n5_distinct(int pas, int v[], int *numar_solutii)
{
    if(pas == NUMAR_EL)
    {
        (*numar_solutii)++;
        printf("Solutie %5d: ",*numar_solutii);
        for(int i=0; i<NUMAR_EL; i++)
            printf("%d", v[i]); 
        printf("\n");
        getc(stdin);      
        return;
    }
    for(int i=0; i<=9; i++)
    {
        if(pas == 0 && i==0)
            i++;

        int proba = 0;
        for(int j=pas-1; j>=0; j--)
            if(v[j]==i)
            {
                proba = 1;
                break;
            }
        if(proba == 1)
            continue;

        v[pas] = i;

        printf("\e[1;1H\e[2J");
        for(int i=0; i<pas; i++)
            printf("%d ", v[i]); 
        getc(stdin);

        n5_distinct(pas+1, v, numar_solutii);
    }
}

//generarea tuturor anagramelor unui cuvant
void anagrame(int pas, int v[], int *numar_solutii, char *cuvant)
{
    if(pas == strlen(cuvant))
    {
        (*numar_solutii)++;
        printf("Solutie %5d: ",*numar_solutii);
        for(int i=0; i<strlen(cuvant); i++)
            printf("%C", cuvant[v[i]]); 
        printf("\n");
        getc(stdin);      
        return;
    }
    for(int i=0; i<strlen(cuvant); i++)
    {
        int proba = 0;
        for(int j=pas-1; j>=0; j--)
            if(v[j]==i)
            {
                proba = 1;
                break;
            }
        if(proba == 1)
            continue;

        v[pas] = i;

        printf("\e[1;1H\e[2J");
        for(int i=0; i<pas; i++)
            printf("%C", cuvant[v[i]]); 
        getc(stdin);

        anagrame(pas+1, v, numar_solutii, cuvant);
    }
}

int main(void)
{
    int numar_solutii;
    int v[10];

    //numar_solutii = 0;
    //n5(0, v, &numar_solutii);

    //numar_solutii = 0;
    //n5_distinct(0, v, &numar_solutii);

    //numar_solutii = 0;
    //anagrame(0, v, &numar_solutii, "TANC");

    
    return 0;
}

