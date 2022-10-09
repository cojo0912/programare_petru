#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define BASIC_LENGTH 100

//https://cplusplus.com/reference/cstdlib/free/

struct person {
    char *name;
    float height;
};

//returneaza 1 daca sunt ordonate crescator
//returneaza -1 daca sunt ordonate descrescator
int comparatie(struct person p1, struct person p2)
{
    if(p1.height < p2.height)
        return 1;

    if(p1.height > p2.height)
        return -1;

    if(p1.height == p2.height)
    {
        if(strcmp(p1.name, p2.name) > 0)
            return -1;
        else
            return 1;
    } 
}

void printPersons (struct person persons[], int nrPersons, int from, int to)
{
    if(to > nrPersons)
        return;

    for(int i=from; i<=to; i++)
        if(persons[i].name != NULL)
            printf("(%s %f) ", persons[i].name, persons[i].height);
    printf("\n");
}

void bubbleSort(struct person persons[], int nrPersons, int *swapped)
{
    *swapped = 0;
    int i, j;
    for (i = 0; i < nrPersons - 1; i++)
        for (j = 0; j < nrPersons - i - 1; j++)
            if (comparatie(persons[j], persons[j+1])==-1)
            {
                struct person aux;
                aux = persons[j];
                persons[j] = persons[j+1];
                persons[j+1] = aux;
                (*swapped)++;
                printf("after swap "); printPersons(persons, nrPersons, 0, nrPersons-1);
            }
    printf("nr of swaps %d\n", *swapped);
}

void insertPerson(struct person persons[], int nrPersons, int newEntry, char *newName, float newHeight)
{
    //verific daca indexul este valid
    //
    if(persons[newEntry].name == NULL)
    {
        //poti sa adaugi
        persons[newEntry].name = (char *) malloc(sizeof(char) * (strlen(newName)+1));
        strcpy(persons[newEntry].name, newName);
        persons[newEntry].height = newHeight;
    }else
    {
        //pozitia este deja ocupara deci, eroare
    }
}

void replacePerson(struct person persons[], int nrPersons,  int newEntry, char *newName, float newHeight)
{
    //verifici daca exista, daca exista ii eliberezi memoria il faci la loc NULL si 0.0
    //il adaugi oricum
}

//https://www.geeksforgeeks.org/merge-sort/
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int *L = (int *) malloc(n1 * sizeof(int));
    if(L == NULL)
        return;

    int *R = (int *) malloc(n2 * sizeof(int));
    if(R == NULL)
    {
        free(L);
        return;
    }

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main(void)
{

    /*int v[10] = {9,8,7,6,5};
    mergeSort(v, 0, 9);
    for(int i=0; i<10; i++)
        printf("%d \n", v[i]);*/ 

    struct person *p = NULL;
    int dimmension = 0;

    int new_index;
    float new_height;
    char new_name[80];
    int swaped = 0;

    char cmd; 
    do {
        printf ("Command? ");
        scanf(" %c",&cmd); // notice the space before the %
    
        switch(cmd)
        {
            case 'n':
                printf("Entries? "); scanf("%d", &dimmension);
                if(p!=NULL)
                {
                    for(int i=0; i<dimmension; i++)
                        if(p[i].name != NULL)
                            free(p[i].name);
                    free(p);
                    p = NULL;
                }
                p = (struct person *) malloc(dimmension * sizeof(struct person));
                for(int i=0; i<dimmension; i++)
                {
                    p[i].height = 0;
                    p[i].name = NULL;
                }
                break;

            case 'p':
                printPersons(p, dimmension, 0, dimmension-1);
                break;

            case 'i':
                printf("Index? "); scanf("%d", &new_index);
                printf("Name? "); scanf("%s", new_name);
                printf("Height? "); scanf("%f", &new_height);
                insertPerson(p,dimmension,new_index,new_name,new_height);
                break;

            case 'b':
                bubbleSort(p, dimmension, &swaped);
                break;

            case 'q': 
                if(p!=NULL)
                {
                    for(int i=0; i<dimmension; i++)
                        if(p[i].name != NULL)
                            free(p[i].name);
                    free(p);
                    p = NULL;
                }
                break;

            default:
                printf("Unknown: %c\n", cmd);
                break;
        }

    } while (cmd != 'q');

    return 0;
}

