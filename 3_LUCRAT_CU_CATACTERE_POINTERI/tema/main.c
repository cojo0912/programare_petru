#include <stdio.h>
#include <string.h>
#define LENGTH 100

void printString(char string[])
{
    for(int i=0; i<LENGTH;i++)
    {
        if(string[i]==0)
            printf("\\0");
        else 
            printf("%c", string[i]);
    }
    printf("\n");
}

void insertName(char *startPos[], int *nrNames, char newName[])
{
    strcpy(startPos[*nrNames], newName);
    startPos[*nrNames+1] = &startPos[*nrNames][strlen(newName)+1];
    (*nrNames)++;
}

void printNames(char names[], char *startPos[], int nrNames)
{
    for(int i=0; i<nrNames; i++)
    printf("%d %d %s\n", startPos[i]-names, strlen(startPos[i])+1,startPos[i]); 
}

//strcmp

int main(void)
{
    char names[LENGTH];
    memset(names, 0, LENGTH);
    //strcpy(&names[49], "Asterix");

    char* startPos[LENGTH];
    memset(startPos, 0, LENGTH);
    startPos[0] = &names[0];
    int nrNames = 0;

    insertName(startPos, &nrNames, "ANA");
    printString(names);
    insertName(startPos, &nrNames, "ION");
    printString(names);
    insertName(startPos, &nrNames, "GICA");
    printString(names);
    printNames(names, startPos, nrNames);
    return 0;

    char cmd; 
    do {
        printf ("Command? ");
        scanf(" %c",&cmd); // notice the space before the %
    
        switch(cmd)
        {
            case 'q':
                break;

            default:
                printf("Unknown: %c\n", cmd);
                break;
        }

    } while (cmd != 'q');

    return 0;
}

