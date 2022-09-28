#include <stdio.h>
#include <string.h>

#define LENGHT 30


void printArray(char a[], int lenght){
    // shimbare switch
     printf("[");
    for(int i = 0; i < lenght; i++){
       if(i > 0)
       printf(",");
        if(a[i] == '\0')
                printf("\\0");
            
            else if(a[i] == '\n')
                    printf("\\n");
                
            else printf("%c", a[i]);
        
    }
    printf("]\n");
}

void printString(char str[]){
    int i = 0;
    printf("\"");
    while(str[i] != '\0'){
        putchar(str[i]);
        i++;
    }
    printf("\"\n");
}

void readLine(char str[], int lenght){
    int i = 0;
    char x;
    do
    {
        x = getchar();
        if(i < lenght - 1)
        {
            if(x == '\n')
                str[i] = '\0';
            else 
                str[i] = x;
        }
        
        if(i == lenght - 1)
            str[i] = '\0';

        i++;
    } while (x!='\n');
}

int findFirstOccurrence(char str[], char aChar)
{
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] == aChar)
            return i;
        i++;
    }
    return -1;
}

int isNumeric(char x)
{
    if(x>='0' && x<='9')
        return 1;
    else
        return 0;
}

int readInt(char str[], int length)
{
    int n = 0;
    if(length == 0)
        return -1;

    for(int i = 0; i<length; i++)
    {
        if(isNumeric(str[i]) == 1)
            n = n * 10 + (str[i] - '0');
        else 
        {
            if(i>0)
                return n;
            else 
                return -1;
        }
    }
    return n;
}

int main(void){
    
    /*char string1[12] = "\nhello";
    char string2[12] = "hello\n";
    char string3[12] = "hello\n\0you\n";
    char string4[12] = "0123456789A";
    */

   /*printf("%d\n", readInt("0123", 4));
   printf("%d\n", readInt("0123x", 4));
   printf("%d\n", readInt("x123", 4));
   printf("%d\n", readInt("x   ", 4));
   printf("%d\n", readInt("", 0));*/
    
    char string[LENGHT] = "";
    char parameter[LENGHT] = "";
    char currString[LENGHT] = "";
    /*printArray(string1, 12);
    printArray(string2, 12);
    printArray(string3, 12);
    printArray(string4, 12);
    printString(string1);
    printString(string2);
    printString(string3);
    printString(string4);
    */
    
    do {
        printf("Command? ");
        
        readLine(string, LENGHT);
        
        switch (string[0]) 
        {
            case 'q':
                printf("Bye!\n");
                break;

            case 'p':
                printf("The current string is: ");
                printString(currString);
                break;
                
            case 'a':
                printf("The current array is: ");
                printArray(currString, LENGHT);
                break;

            case 's':
                printf("Please enter a string? ");
                readLine(currString, LENGHT);
                break;

            case 'o':
                printf("Find first occurrence of which character? ");
                readLine(parameter, LENGHT);
                printf("The first occurrence of '%c' is at index %d\n", 
                    parameter[0],
                    findFirstOccurrence(currString, parameter[0]));
                break;

            default:
                printf("Unknown command '%c'\n",string[0]);
                break;

        }
    } while (string[0] != 'q');

}