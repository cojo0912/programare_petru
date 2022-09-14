#include <stdio.h>

int functie_1(int x2)
{
    printf("%d", x2);
    return 1;
}

int main()
{
    // informatica vs programare
    // tipuri de date
        // toate sunt numere
    
    //1 bit
    //octet/byte 1111 1111   

    int x = 1;
    functie_1(x);

    // instructiuni de baza while do while for if switch

    switch(x)
    {
        case 0:
            printf("salut0!");
            break;
    
        case 1:
            printf("salut1!");
            break;

        case 2:
            printf("salut2!");
            break;

        default:
            printf("salut! default");
            break;

    }

    x = 0;
    do
    {
        printf("%d\n", x);
        x++;
    } while (x<5);
       
    x=77;
    // pointeri
    int *p = &x;
    int v[100];

    int **p2;


    // aray uri

    // functie parametrii etc
    // lucrat cu caractere
    
    // ascii
    // documentatii
    // printf scanf
    // getchar putchar
    return 0;
}