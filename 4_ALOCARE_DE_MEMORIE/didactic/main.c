#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMAR_EL 5

//cum se aloca memoria
//static si dinamic
//stack si heap

//https://cplusplus.com/reference/cstdlib/malloc/
//https://cplusplus.com/reference/cstdlib/calloc/
//https://en.cppreference.com/w/c/memory/realloc

struct str_ex
{
    int a;
    char b;
};

int main(void)
{
    struct str_ex * pointer = NULL;

    pointer = (struct str_ex *) malloc(NUMAR_EL * sizeof(struct str_ex));
    if(pointer == NULL)
    {
        printf("malloc, nu a functionat\n");
        return 0;
    }
    pointer[0].a = 11;
    pointer[0].b = 'b';

    printf("%d %c\n", pointer[0].a , pointer[0].b);
    free(pointer);

    pointer = (struct str_ex *) calloc(NUMAR_EL, sizeof(struct str_ex));
    if(pointer == NULL)
    {
        printf("calloc, nu a functionat\n");
        return 0;
    }

    pointer[0].a = 12;
    pointer[0].b = 'c';
    printf("%d %c\n", pointer[0].a , pointer[0].b);

    

    pointer = (struct str_ex *) realloc(pointer, 3*NUMAR_EL * sizeof(struct str_ex));
    if(pointer == NULL)
    {
        printf("realloc, nu a functionat\n");
        return 0;
    }

    printf("%d %c\n", pointer[0].a , pointer[0].b);
    free(pointer);

    
    return 0;
}

