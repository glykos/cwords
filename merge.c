#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

int     c[500000];
char    wori[500000][6];
char    w[500000][6];


int main()
{
    int     N=0;
    int     added, current=0;
    int     i, k, dist, printed;

    while( scanf("%s", wori[N] ) == 1 )
    {
        strcpy( w[N], wori[N] );

        for( i=0 ; i < 5 ; i++ )
            if ( w[N][i] > 'Z' )
                w[N][i] -= 6;

        N++;
    }

    fprintf( stderr, "Read %d words.\n", N );


    while ( 1 )
    {
    current++;
    for( i=0 ; i < N ; i++ )
        if ( c[i] == 0 )
            {
                c[i] = current;
                break;
            }

    if ( i == N )
        break;


    added = 1;
    printed = 0;
    
    while( added > 0 )
    {
        added = 0;

        #pragma omp parallel for private( i,dist)
        for( i=0 ; i < N ; i++ )
        {
            if ( c[i] == current )
            {
                for( k=0 ; k < N ; k++ )
                {
                    if ( c[k] == 0 )
                    {
                    dist = 4*abs(w[i][0]-w[k][0]) + 3*abs(w[i][1]-w[k][1]) + 2*abs(w[i][2]-w[k][2]) + abs(w[i][3]-w[k][3]) + abs(w[i][4]-w[k][4]);
                    if ( dist <= 10 )
                    {
                        c[k] = current;
                        added++;
                    }
                    }
                }
            }
        }
    
        if ( added > 0 ) 
            { 
                fprintf(stderr, "Added %6d members to cluster %3d\n", added, current );
                printed = 1;
            }
    }
    
    if ( printed == 0 )
        fprintf(stderr, "Added %6d member  to cluster %3d\n", 1, current );
    }



    for( i=0 ; i < N ; i++ )
    {
        if ( c[i] > 0 )
            printf("%s %d\n", wori[i], c[i] );
    }


}

