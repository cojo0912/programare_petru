#include <stdio.h>
#include <string.h>
#define MAXSIZE 10



int main(void)
{


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

