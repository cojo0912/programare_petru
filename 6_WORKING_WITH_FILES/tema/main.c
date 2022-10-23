#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define MAXWORDS 60
#define MAXINDEX 10

typedef struct _entry_t {
    char *word;
    int indices[MAXINDEX];
} entry_t;

int print_entry(entry_t * p)
{
    if(p->word!=NULL)
    {
        printf("%10s:", p->word);
        for(int i=0; i<MAXINDEX; i++)
            if(p->indices[i]!=-1) 
                printf(" %d", p->indices[i]);
        printf("\n");
        return 1;
    }else
        return 0;
}

void printConcordance(entry_t concordance[])
{
    int elemente_printare = 0;
    for(int i = 0; i<MAXWORDS; i++)
        elemente_printare += print_entry(&concordance[i]);
    if(elemente_printare == 0)
        printf("lista este goala\n");
}

int does_my_word_exists(entry_t concordance[], char *word)
{
    for(int i=0; i<MAXINDEX; i++)
    {
        if(concordance[i].word != NULL)
            if(strcmp(concordance[i].word, word) == 0)
                return i;
    }
    return -1; 
}

int first_empty_position(entry_t concordance[])
{
    for(int i=0; i<MAXINDEX; i++)
    {
        if(concordance[i].word == NULL)
            return i;
    }
    return -1;
}

void addIndex(entry_t concordance[], char *word, int index)
{
    int pos = does_my_word_exists(concordance, word);

    if(pos == -1)
    {
        printf("Cuvntul nu exieta\n");
        return;
    }

    for(int i=0; i<MAXINDEX; i++)
        if(concordance[pos].indices[i] == -1)
        {
            concordance[pos].indices[i] = index;
            break;
        }
}

void addWord(entry_t concordance[], char *word)
{
    if(does_my_word_exists(concordance, word) >= 0)
        return;

    int available_position = first_empty_position(concordance);
    if(available_position == -1)
    {
        printf("nu mai am loc\n");
        return;
    }

    int new_position = 0;
    if(available_position == 0)
    {
        new_position = 0;
    }else
    {
        while(strcmp(concordance[new_position].word,word) < 0)
        {
            new_position++;
            if(new_position==available_position)
                break;
        }
        for(int i=available_position-1; i>=new_position; i--)
            concordance[i+1] = concordance[i];
    }

    concordance[new_position].word = (char*) malloc(sizeof(char) * (strlen(word)+1));
    strcpy(concordance[new_position].word, word);
    for(int i=0; i<MAXINDEX; i++)
        concordance[new_position].indices[i] = -1;

}

void readFile(entry_t concordance[], char *filename, int *index)
{
    FILE * fisier = NULL;
    fisier = fopen(filename, "r");
    if(fisier == NULL)
    {
        printf("Nu s-a putut deschide fisierul");
        return;
    }

    char cuvant[12];
    while(fscanf(fisier, "%12s", cuvant) == 1 )
    {
        addWord(concordance, cuvant);
        addIndex(concordance, cuvant, *index);
        (*index)++;
    }
    fclose(fisier);
}

int main(void)
{

    entry_t my_array[MAXWORDS];
    for(int i=0; i<MAXWORDS; i++)
    {
        my_array[i].word = NULL;
        for(int j=0; j<MAXINDEX; j++)
            my_array[i].indices[j] = -1;
    }

    char cuvant[11];
    char denumiore_fisier[255];
    int index=0;
    
    char cmd; 
    do {
        printf ("Command? ");
        scanf(" %c",&cmd); // notice the space before the %
    
        switch(cmd)
        {
            // la stergere
            // ai grija cand stergi la eliberezi memoria de la cuvant
            // ai grija sa nu lasi loc liber in vectorul de cuvinte si sa le muti pe restul



            case 'p':
                printConcordance(my_array);
                break;
            
            case 'w':
                printf("Ce cuvant vrei? ");
                scanf("%s", cuvant);
                addWord(my_array, cuvant);
                break;

            case 'i':
                printf("Ce cuvant index vrei? "); 
                scanf("%s", cuvant);
                scanf("%d", &index);
                addIndex(my_array, cuvant, index);
                break;

            case 'r':
                printf("Ce nume de fisier vrei? "); 
                scanf("%s", denumiore_fisier);
                readFile(my_array, denumiore_fisier, &index);
                break;

            default:
                printf("Unknown: %c\n", cmd);
                break;
        }

    } while (cmd != 'q');

    return 0;
}

