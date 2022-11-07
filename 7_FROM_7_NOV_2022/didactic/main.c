#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//facem un dictrionat cu lungime variabila 
//numarul maxim de cuvinte se citeste lapornirea programului
//ulterior se creaza o lista de acest maxim numar de cuvinte
//dupa care in dictionar, se for permite urmatoarele operatii
//cautarea unui cuvant adaugarea stergea lui (corecta cu alocare si dezalocare)

//similar se va face si o lista de definitii corespunzatoare cuvintelor
//definitiile sunt texte ce pot fi despartie prin spatiu
//evident ca se va face si o lista de corespondeta intre cuvinte si definitii

//se dorec adaugarea unei definirtii pentru un cuvant, modificarea acesteia, stergerea acesteia
//dictionarul poate afisa cuvintele in ordinberea inserarii lor cu sau fara definii labnga
//si poate fi sortat

//picat 3

//vreau afisarea cuvintelor in mod recursiv
//nu ai vopie for in functia ta


struct defs
{
    int *coresdpondenta;
    char **def;
};

int free_position(char **cuv, int nr_cuv_max)
{
    for(int i=0; i<nr_cuv_max; i++)
        if(cuv[i] == NULL)
            return i;
    return -1;
}

void adaug_cuv(char **cuv, int nr_cuv_max, char *cuvant)
{
    int fp = free_position(cuv, nr_cuv_max);
    if(fp == -1)
    {
        printf("Dictionar plin\n");
        return;
    }
    
    cuv[fp] = (char*) malloc(sizeof(char)*(strlen(cuvant)+1));
    strcpy(cuv[fp], cuvant);
}

void print_cuv(char **cuv, int nr_cuv_max)
{
    for(int i=0; i<nr_cuv_max; i++)
        if(cuv[i] != NULL)
            printf("%s \n", cuv[i]);
}

int cautare(char **cuv, int nr_cuv_max, char *cuvant)
{
    for(int i=0; i<nr_cuv_max; i++)
        if(cuv[i]!=NULL)
            if(strcmp(cuv[i], cuvant) == 0)
                return i;
    return -1;
}

void stergere(char **cuv, int nr_cuv_max, char *cuvant)
{
    int index = cautare(cuv, nr_cuv_max, cuvant);
    if(index == -1)
    {
        printf("cuvantul nu este in dictionar\n");
        return;
    }
    free(cuv[index]);
    cuv[index] = NULL;
}

void adaugare_def(char **cuv, int nr_cuv_max, struct defs *definitii, char * cuvant, char *def)
{
    int index = cautare(cuv, nr_cuv_max, cuvant);
    if(index == -1)
    {
        printf("cuvantul nu este in dictionar\n");
        return;
    }

    //verificam daca resp cuvant are definitie
    if(definitii->coresdpondenta[index] == -1)
    {      
        int index_def = free_position(definitii->def, nr_cuv_max);
        definitii->def[index_def] = (char*) malloc(sizeof(char)*(strlen(def)+1));
        strcpy(definitii->def[index_def], def);
        definitii->coresdpondenta[index] = index_def;
    }else
    {
        free(definitii->def[definitii->coresdpondenta[index]]);
        definitii->def[definitii->coresdpondenta[index]] = (char*) malloc(sizeof(char)*(strlen(def)+1));
        strcpy(definitii->def[definitii->coresdpondenta[index]], def);
    }
}

void printare_def(char **cuv, int nr_cuv_max, struct defs *definitii)
{
    for(int i=0; i<nr_cuv_max; i++)
        if(cuv[i] != NULL)
        {
            printf("%s - ", cuv[i]);
            if(definitii->coresdpondenta[i]==-1)
                printf("cuvantul nu are definitie\n");
            else
                printf("%s\n", definitii->def[definitii->coresdpondenta[i]]);
        }
}

void printare_def_rec(char **cuv, int nr_cuv_max, struct defs *definitii, int pas)
{
    if(pas == nr_cuv_max)
        return;
    if(cuv[pas]!=NULL)
    {
        printf("%s - ", cuv[pas]);
        if(definitii->coresdpondenta[pas]==-1)
            printf("cuvantul nu are definitie\n");
        else
            printf("%s\n", definitii->def[definitii->coresdpondenta[pas]]);
    }
    printare_def_rec(cuv, nr_cuv_max,definitii, pas+1);
}

void stergere_def(char **cuv, int nr_cuv_max, struct defs *definitii, char * cuvant)
{
    int index = cautare(cuv, nr_cuv_max, cuvant);
    if(index == -1)
    {
        printf("cuvantul nu este in dictionar\n");
        return;
    }

    if(definitii->coresdpondenta[index] == -1)
    {
        printf("cucantul nu are definite\n");
    }else
    {
        free(definitii->def[definitii->coresdpondenta[index]]);
        definitii->def[definitii->coresdpondenta[index]] = NULL;
        definitii->coresdpondenta[index] = -1;
    }
}

int compara(char *c1, char *c2)
{
    if(c1 == NULL && c2 != NULL)
        return -1;
    if(c1 != NULL && c2 == NULL)
        return 1;
    if(c1 == NULL && c2 == NULL)
        return 0;
    
    return strcmp(c1,c2);
}

void sortare(char **cuv, int nr_cuv_max, struct defs *definitii)
{
    int este_sortat = 0;
    while(este_sortat == 0)
    {
        este_sortat = 1;
        for(int i=0; i<nr_cuv_max-1; i++)
            if(compara(cuv[i], cuv[i+1])>0)
            {
                este_sortat = 0;
                char* aux = cuv[i];
                cuv[i] = cuv[i+1];
                cuv[i+1] = aux;

                int auxc = definitii->coresdpondenta[i];
                definitii->coresdpondenta[i] = definitii->coresdpondenta[i+1];
                definitii->coresdpondenta[i+1] = auxc;
            }
    }
}


int main(void)
{
    char **cuv;
    int nr_cuvinte;
    struct defs definitii;

    printf("Introduceti nr maxim de cuv in dictgionar: \n");
    //scanf("%d", &nr_cuvinte);
    nr_cuvinte = 100;

    cuv = (char**)malloc(sizeof(char*) * nr_cuvinte);
    for(int i=0; i<nr_cuvinte; i++)
        cuv[i] = NULL;

    definitii.coresdpondenta = (int*)malloc(sizeof(int) * nr_cuvinte);
    for(int i=0; i<nr_cuvinte; i++)
        definitii.coresdpondenta[i] = -1;

    definitii.def = (char**)malloc(sizeof(char*)* nr_cuvinte);
    for(int i=0; i<nr_cuvinte; i++)
        definitii.def[i] = NULL;

    adaug_cuv(cuv, nr_cuvinte, "roxana");
    adaug_cuv(cuv, nr_cuvinte, "are");
    adaug_cuv(cuv, nr_cuvinte, "mere");
    adaug_cuv(cuv, nr_cuvinte, "pere");
    adaug_cuv(cuv, nr_cuvinte, "portocale");
    adaug_cuv(cuv, nr_cuvinte, "banane");
    print_cuv(cuv, nr_cuvinte);

    printf("Gasit pe pozitia %d\n", cautare(cuv, nr_cuvinte, "banane"));
    stergere(cuv, nr_cuvinte, "banane");
    stergere(cuv, nr_cuvinte, "banane");
    stergere(cuv, nr_cuvinte, "are");
    print_cuv(cuv, nr_cuvinte);
    //functie care introduce un cuvant pe prima poztie libera    

    //char definitie[1024];
    //fgets(definitie, 1024, stdin);
    adaugare_def(cuv,nr_cuvinte,&definitii,"portocale", "cadou mos nicolae");
    adaugare_def(cuv,nr_cuvinte,&definitii,"portocale", "cadou mos nicolae22222");
    stergere_def(cuv,nr_cuvinte,&definitii,"portocale");
    printare_def(cuv,nr_cuvinte,&definitii);
    adaugare_def(cuv,nr_cuvinte,&definitii,"portocale", "cadou mos nicolaeee");
    adaugare_def(cuv,nr_cuvinte,&definitii,"roxana", "nume romanesc");
    printare_def(cuv,nr_cuvinte,&definitii);
    sortare(cuv,nr_cuvinte,&definitii);
    printare_def(cuv,nr_cuvinte,&definitii);
    printare_def_rec(cuv,nr_cuvinte,&definitii, 0);

    //fa si meniul

    //aliberarea definitiilor
    free(definitii.coresdpondenta);
     for(int i=0; i<nr_cuvinte; i++)
        if(definitii.def[i] != NULL)
            free(definitii.def[i]);
    free(definitii.def);

    //eliberarea cuvintelor din dictionar
    for(int i=0; i<nr_cuvinte; i++)
        if(cuv[i] != NULL)
            free(cuv[i]);
    free(cuv);
    return 0;
}

