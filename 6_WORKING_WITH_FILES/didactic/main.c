#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUMAR_EL 3


int main(void)
{
    //stdin
    //stdout
    //stder

    //FILE *fopen(const char *filename, const char *mode);
    /*
    r  - open for reading (fails if the files exists)
    w  - open for writing (file need not exist)
    a  - open for appending (file need not exist)
    r+ - open for reading and writing, start at beginning
    w+ - open for reading and writing (overwrite file)
    a+ - open for reading and writing (append if file exists)
    */

    /*
    Functii care citesc si scriu in fisier:
    fscanf(fisier, "formatare", variabile);
    fprintf(fisier, "formatare", variabile);
    fgetc(fisier)
    fputc(char, fisier)
    Scriere si citire linie cu linie
    fgets(string, fisier) 
    fputs(string, fisier)
    */

    FILE *file_handler = NULL;
    file_handler = fopen("fisier.txt", "r+");
    if(file_handler == NULL)
    {
        printf("Nu s-a putut deschide fisiereul!");
        return 0;
    }

    char x;
    do{
        x = fgetc(file_handler);
        printf("%c", x);
    }while(x!=EOF);

            
    fputs("Scriere in fisier\n", file_handler);

    fclose(file_handler);
    return 0;
}

