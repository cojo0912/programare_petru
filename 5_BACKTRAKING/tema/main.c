#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define BASIC_LENGTH 100

typedef struct {
    char *grid;
    int maxX;
    int maxY;
} navigation_t;

typedef struct {
    int x;
    int y;
} position_t;

void printf_clear_and_wait(char * v)
{
    printf("\e[1;1H\e[2J"); // printf cleat screen
    printf("%s\n\n",v);
    getc(stdin);
}

int calcutate_coord(int lin, int col, navigation_t nav)
{
    return lin * (nav.maxY+1) + col;
}

int x[100], y[100];

int findOnePath(navigation_t nav, int x, int y, int length)
{
    if(x == -1 || y == -1 || x == nav.maxX || y == nav.maxY)
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == '#')
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == 'D')
    {
        printf("Gasit drum de lungime: %d\n", length);
        getc(stdin);
        return length;
    }
    if(nav.grid[calcutate_coord(x,y,nav)] == '-')
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == '+')
        return 0;

    nav.grid[calcutate_coord(x,y,nav)] = '+';
    printf_clear_and_wait(nav.grid);

    int lenght = findOnePath(nav, x-1, y, length+1);
    if(lenght!=0)
        return lenght;

    lenght = findOnePath(nav, x, y+1, length+1);
    if(lenght!=0)
        return lenght;

    lenght = findOnePath(nav, x+1, y, length+1);
    if(lenght!=0)
        return lenght;

    lenght = findOnePath(nav, x, y-1, length+1);
    if(lenght!=0)
        return lenght;

    nav.grid[calcutate_coord(x,y,nav)] = '-';
    return 0;
}

int findPath(navigation_t nav, int x, int y, int length)
{
    if(x == -1 || y == -1 || x == nav.maxX || y == nav.maxY)
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == '#')
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == 'D')
    {
        printf("Gasit drum de lungime: %d\n", length);
        getc(stdin);
        return length;
    }
    if(nav.grid[calcutate_coord(x,y,nav)] == '-')
        return 0;
    if(nav.grid[calcutate_coord(x,y,nav)] == '+')
        return 0;

    
    nav.grid[calcutate_coord(x,y,nav)] = '+';
    printf_clear_and_wait(nav.grid);

    int max_len = 0;
    int lenght = findPath(nav, x-1, y, length+1);
    if(lenght>=max_len)
        max_len = lenght;

    lenght = findPath(nav, x, y+1, length+1);
    if(lenght>=max_len)
        max_len = lenght;

    lenght = findPath(nav, x+1, y, length+1);
    if(lenght>=max_len)
        max_len = lenght;

    lenght = findPath(nav, x, y-1, length+1);
    if(lenght>=max_len)
        max_len = lenght;

    nav.grid[calcutate_coord(x,y,nav)] = '.';
    return max_len;
}

int main(void)
{
    navigation_t nav;
    
    
    char cmd; 
    do {
        printf ("Command? ");
        scanf(" %c",&cmd); // notice the space before the %
    
        switch(cmd)
        {
            case 'i':
                printf("randuri? "); scanf("%d", &nav.maxX);
                printf("coloane? "); scanf("%d", &nav.maxY);
                if(nav.grid == NULL)
                    free(nav.grid);
                nav.grid = (char* ) malloc( nav.maxX*(nav.maxY+1) * sizeof(char));
                for(int i=0; i<nav.maxX; i++)
                {
                    printf("Citeste ranbdul %d ", i);
                    scanf("%s", &(nav.grid[calcutate_coord(i,0,nav)]));
                }
                
                printf("%s\n\n",nav.grid);
                //de facut extra verificari
                break;

            case 's':
                //il faci tu
                break;

            default:
                printf("Unknown: %c\n", cmd);
                break;
        }

    } while (cmd != 'q');

    if(nav.grid == NULL)
        free(nav.grid);
    return 0;
}

