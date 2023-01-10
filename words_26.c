#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float   dat[11000000][5];
int     indeces[11000000];
int     N;


int main()
{
    int     i, k;
    float   max1, min1, max2, min2, max3, min3, max4, min4, max5, min5;

    while( scanf("%d %f %f %f %f %f", &i, &dat[N][0], &dat[N][1], &dat[N][2], &dat[N][3], &dat[N][4] ) == 6 )
    {
        indeces[N] = i;
        N++;
    }

    min1 = dat[0][0]; min2 = dat[0][1]; min3 = dat[0][2]; min4 = dat[0][3]; min5 = dat[0][4];
    max1 = dat[0][0]; max2 = dat[0][1]; max3 = dat[0][2]; max4 = dat[0][3]; max5 = dat[0][4];
    for ( i=0 ; i < N ; i++ )
    {
        if ( dat[i][0] < min1 ) min1 = dat[i][0];
        if ( dat[i][0] > max1 ) max1 = dat[i][0];
        if ( dat[i][1] < min2 ) min2 = dat[i][1];
        if ( dat[i][1] > max2 ) max2 = dat[i][1];
        if ( dat[i][2] < min3 ) min3 = dat[i][2];
        if ( dat[i][2] > max3 ) max3 = dat[i][2];
        if ( dat[i][3] < min4 ) min4 = dat[i][3];
        if ( dat[i][3] > max4 ) max4 = dat[i][3];
        if ( dat[i][4] < min5 ) min5 = dat[i][4];
        if ( dat[i][4] > max5 ) max5 = dat[i][4];
    }

    fprintf(stderr, "Read %d data points. Limits are : \n", N );
    fprintf(stderr, "%f %f %f %f %f %f %f %f %f %f\n", min1, max1, min2, max2, min3, max3, min4, max4, min5, max5 );

    for ( i=0 ; i < N ; i++ )
    {
        printf("%c", (char)( 'A'+(int)((dat[i][0]-min1)/((max1-min1)/25.0)) ) );
        printf("%c", (char)( 'A'+(int)((dat[i][1]-min2)/((max2-min2)/25.0)) ) );
        printf("%c", (char)( 'A'+(int)((dat[i][2]-min3)/((max3-min3)/25.0)) ) );
        printf("%c", (char)( 'A'+(int)((dat[i][3]-min4)/((max4-min4)/25.0)) ) );
        printf("%c\n", (char)( 'A'+(int)((dat[i][4]-min5)/((max5-min5)/25.0)) ) );
    }

}

