#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


#define     MAX_STRUCT      25000000
#define     MAX_PCs         10


float   dat[ MAX_STRUCT ][ MAX_PCs ];
int     indeces[ MAX_STRUCT ];
float   min[ MAX_PCs ];
float   max[ MAX_PCs ];


int main()
{
    int     i, k, c, off;
    int     N;
    int     DIV;
    int     tot_col;
    float   val;
    char    in[1000];
    char    *p;


    /* Find number of columns & read data */
    if ( fgets( in, 1000, stdin ) == NULL )
        {
                fprintf(stderr, "Failed to read any input (?!). Abort.\n");
                exit( 1 );
        }
    p = &in[0];
    tot_col = 0;
    while ( sscanf( p, "%f%n", &val, &off) == 1 )
            {
                    tot_col++;
                    p += off;
            }
    
    N = 0;
    do {
        p = &in[0];

        if ( sscanf( p, "%d%n", &i, &off ) == 1 )
            indeces[N] = i;
        else
            {
                fprintf(stderr, "Failed to read PCs at line %s\n", in );
                exit( 1 );
            }
        
        p += off;
        for ( k=0 ; k < tot_col-1 ; k++ )
            if ( sscanf( p, "%f%n", &val, &off ) == 1 )
                {
                    dat[N][k] = val;
                    p += off;
                }
            else
                {
                    fprintf(stderr, "Failed to read PCs at line %s\n", in );
                    exit( 1 );
                }

        N++;

    } while ( fgets( in, 1000, stdin ) != NULL );

    fprintf(stderr, "Read %d vectors (%d-dimensional).\n", N, tot_col-1 );


    /* Determine limits & grid */
    for ( i=0 ; i < tot_col-1 ; i++ )
    {
        min[i] = dat[0][i];
        max[i] = dat[0][i];
    }

    for ( i=0 ; i < N ; i++ )
    {
        for ( k=0 ; k < tot_col-1 ; k++ )
        {
            if ( dat[i][k] > max[k] )
                max[k] = dat[i][k];

            if ( dat[i][k] < min[k] )
                min[k] = dat[i][k];
        }
    }

    /* fprintf(stderr, "%f %f %f %f\n", min[0], max[0], min[1], max[1] );   */
    /* DIV = (int)((2*pow( N, (1.0l/(tot_col-1))))+0.50);                   */

    DIV = (int)((2*pow( N, 0.20l))+0.50);

    if ( DIV > 51 )
        DIV = 51;
    if ( DIV < 5 )
        DIV = 5;

    fprintf(stderr, "Grid along each dimension set to %d.\n", DIV );


    /* Prepare word list */
    for ( i=0 ; i < N ; i++ )
    {
        for ( k=0 ; k < tot_col-1 ; k++ )
        {
            c = 'A'+(int)((dat[i][k]-min[k])/((max[k]-min[k])/DIV));
            if ( c > 'Z' ) 
                c += 6;
            printf("%c", (char)(c) );
        }
        printf("\n");
    }

}

