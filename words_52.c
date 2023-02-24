#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

float   dat[25000000][5];
int     indeces[25000000];
int     N;
int     DIV;

int main()
{
    int     i, k;
    float   max1, min1, max2, min2, max3, min3, max4, min4, max5, min5;
    char    in[1000];

    N = 0;
    while( fgets( in, 1000, stdin ) != NULL )
    {
        if ( sscanf(in, "%d %f %f %f %f %f", &i, &dat[N][0], &dat[N][1], &dat[N][2], &dat[N][3], &dat[N][4] ) == 6 )
        {
            indeces[N] = i;
            N++;
        }
        else
        {
            fprintf(stderr, "Failed to read PCs at line %s\n", in );
            exit( 1 );
        }
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

    DIV = (int)((2*pow( N, 0.20l))+0.50); 
    if ( DIV > 51 )
        DIV = 51;
    if ( DIV < 5 )
        DIV = 5;

    fprintf(stderr, "Read %d data points.\n", N );
    fprintf(stderr, "Will divide each dimension in %d parts.\n", DIV );

    for ( i=0 ; i < N ; i++ )
    {
        k = 'A'+(int)((dat[i][0]-min1)/((max1-min1)/DIV));
        if ( k > 'Z' ) k += 6;
        printf("%c", (char)(k) );

        k = 'A'+(int)((dat[i][1]-min2)/((max2-min2)/DIV));
        if ( k > 'Z' ) k += 6;
        printf("%c", (char)(k) );
        
        k = 'A'+(int)((dat[i][2]-min3)/((max3-min3)/DIV));
        if ( k > 'Z' ) k += 6;
        printf("%c", (char)(k) );
        
        k = 'A'+(int)((dat[i][3]-min4)/((max4-min4)/DIV));
        if ( k > 'Z' ) k += 6;
        printf("%c", (char)(k) );
        
        k = 'A'+(int)((dat[i][4]-min5)/((max5-min5)/DIV));
        if ( k > 'Z' ) k += 6;
        printf("%c\n", (char)(k) );

    }

}

