#include <stdio.h>
#include <string.h>

//https://cplusplus.com/reference/cstring/

int main(void)
{
    char v[100];
    memset(v, 0, 100);
    printf("%d\n", strlen(v));
    memcpy(v, "12345", 2);
    
    printf("%s", v);
    
    return 0;
}

