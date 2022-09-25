#include <stdio.h>
#include <string.h>
#define MAXSIZE 10

void print(float matrix[MAXSIZE][MAXSIZE], int rowsA, int columnsA)
{
    for(int i=0; i<rowsA; i++)
    {
        for(int j=0; j<columnsA; j++)
            printf("%8.2f ", matrix[i][j]);
        printf("\n");
    }
}

void minorMatrix (float matrixA[MAXSIZE][MAXSIZE], int rowsA, int columnsA,
                  int r, int c, float min[MAXSIZE][MAXSIZE])
{
    int ii = 0, jj = 0;
    for(int i=0; i<rowsA; i++)
    {
        if(i!=r)
        {
            for(int j=0; j<columnsA; j++)
            {
                if(j!=c)
                {
                    min[ii][jj] = matrixA[i][j];
                    jj++;
                }
            }
            ii++;
            jj = 0;
        }
    }
}

float determinant (float matrixA[MAXSIZE][MAXSIZE], int rowsA, int columnsA)
{
    float det;
    if (rowsA == 1 && columnsA == 1) det = matrixA[0][0];
    else if (rowsA == 2 && columnsA == 2) det = matrixA[0][0]*matrixA[1][1] -  matrixA[0][1]*matrixA[1][0];
    else {
        det = 0;
        for(int c = 0; c<columnsA; c++)
        {
            int sign = (c % 2 ? -1 : +1);
            float m[MAXSIZE][MAXSIZE];
            minorMatrix(matrixA,rowsA,columnsA,0,c,m);
            det += sign * matrixA[0][c] * determinant(m, rowsA-1, columnsA-1);
        }
    }
    return det; 
}

/*
    if(ceva)
        R1
    else 
        R2

    if(c%2)
        sign = -1
    else 
        sign = 1

    0 false
    1 adevarat
    (ceva?R1:R2)
*/

void printRecursive (float matrixA[MAXSIZE][MAXSIZE],
                    int rowsA, int columnsA, int currentRow, int currentColumn)
{
    //printf("enter printRecursive with current row=%d column=%d\n", currentRow, currentColumn);
    //conditie de oprire
    if(currentRow == rowsA)
        return;

   
    int nextRow;
    int nextColumn;
    if(currentColumn == columnsA)
    {
        nextColumn = 0;
        nextRow = currentRow + 1;
    }else
    {
        nextColumn = currentColumn + 1;
        nextRow = currentRow;
    }
    printRecursive (matrixA, rowsA, columnsA, nextRow, nextColumn);
    printf("current row=%d column=%d value=%8.2f\n", currentRow, currentColumn, matrixA[currentRow][currentColumn]);

    //printf("exit printRecursive with current row=%d column=%d\n", currentRow, currentColumn);
}

//jspaint
int main(void){

    float A[MAXSIZE][MAXSIZE] = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printRecursive(A,3,3,0,0);

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

