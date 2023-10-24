#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORDS 12
#define MAXLEN 20

// -0.3
// -0.5
// -1

void printWordList(char *wordList[MAXWORDS])
{
    // %s primeste pointer
    for(int i=0; i<MAXWORDS; i++)
        if(wordList[i] != NULL)
            printf("\"%s\" is referenced for entries %d\n", wordList[i], i);
}

int compara(char *s1, char *s2)
{
    if(s1 == NULL && s2 == NULL)
        return 0;
    
    if(s1 == NULL && s2 != NULL)
        return 1;

    if(s1 != NULL && s2 == NULL)
        return -1;    

    return strcmp(s1,s2);

}

void insertWord(char *wordList[MAXWORDS], char *word)
{
    int contor = 0;
    for(int i=0; i<MAXWORDS; i++)
        if(wordList[i] == NULL)
            contor ++;
    
    if(contor == 0)
    {
        printf("Lista mea e full");
        return;
    }

    for(int i=0; i<MAXWORDS; i++)
    {
        if(compara(word, wordList[i])<=0)
        {
            for(int j=MAXWORDS-1; j>i; j--)
                wordList[j] = wordList[j-1];
            wordList[i] = (char*) malloc(sizeof(char)*(strlen(word) + 1));
            strcpy(wordList[i], word);
            break;
        }
    }                    
}

int main(void)
{
    char *wordList[MAXWORDS];
    for(int i=0; i<MAXWORDS; i++)
        wordList[i] = NULL;

    printWordList(wordList);
    insertWord(wordList, "aaaaa");
    insertWord(wordList, "ccccc");
    insertWord(wordList, "bbbbb");
    printWordList(wordList);

    return 0;
}