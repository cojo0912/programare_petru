#include <stdio.h>
#include <string.h>

struct STR1
{
    float a;
    int b[2];
};
typedef struct STR1 STRUCT1;

struct STR2
{
    float A[10][10];
    int c;
    int r;
};

void sortare(int v[], int len)
{
    int sorteaza = 1;
    while(sorteaza == 1)
    {
        sorteaza = 0;
        for(int i=0; i<len-1; i++)
        {
            if(v[i]>v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sorteaza = 1;
            }
        }
    }
}

void printRecursiv(int v[],int len, int pas)
{
    printf("PAS: %d\n", pas);
    //conditie de oprire 
    if(pas == len)
    {
        printf("Ma opresc!\n");
        return;
    }

    //apel recursiv
    printRecursiv(v, len, pas+1);

    //actiuni specifice
    printf("NR: %d \n", v[pas]);

}

// 0 - afiseaza 0
// 1 - afiseaza 1
// 2 - afiseaza 2
// 3 - oprim 

void printRecursiv2(int v[], int pas)
{
    //conditie de oprire 
    if(pas == 0)
        return;

    //apel recursiv
    printRecursiv2(v, pas-1);

    //actiuni specifice
    printf("%d ", v[pas-1]);
}

int main(void)
{
    printf("%lu %lu %lu\n", sizeof(int), sizeof(float), sizeof(STRUCT1));
    STRUCT1 x;
    x.a = 1.5;
    x.b[0] = 2;
    x.b[1] = 34;
    //daca mai trebuie sa iti zic ceva
    // %06d
    printf("<>%8.2f<>%-6d<>%05d<>\n", x.a, x.b[0], x.b[1]);

    int v[10] = {8,7,6,5,4,3,2,1};
    sortare(v, 10);
    for(int i=0; i<10; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    printRecursiv(v,3, 0);
    printf("\n");
    printRecursiv2(v, 10);
    return 0;
}

