#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a, b;

    while( scanf("%c%c\n", &a, &b) == 2 )
    {
        printf("%d %d\n", a-'A', b-'A' );
    }

}

