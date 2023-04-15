#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>


#define     MAX_STRUCT      25000000
#define     MAX_PCs         10
#define     MAX_CLU         500000

int     c[ MAX_CLU ];
char    wori[ MAX_CLU ][ MAX_PCs+1 ];
char    w[ MAX_CLU ][ MAX_PCs+1 ];


int main()
{
    int     N=0;
    int     added, current=0;
    int     i, k, m, dist, printed;
    int     nofPCs = -1; 
    int     cut;

    /* Read list of words */
    while( scanf("%s", wori[N] ) == 1 )
    {
        if ( nofPCs < 0 )
            nofPCs = strlen( wori[N] );

        strcpy( w[N], wori[N] );

        for( i=0 ; i < nofPCs ; i++ )
            if ( w[N][i] > 'Z' )
                w[N][i] -= 6;

        N++;
    }

    fprintf( stderr, "Read %d words (%d-dimensional vectors).\n", N, nofPCs );


    /* Find other words with a distance less than cutoff & assign to same cluster */
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
     
    cut = nofPCs / 2;
    if ( cut < 1 )
        cut = 1;

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
                        dist = 4*abs(w[i][0]-w[k][0]) + 3*abs(w[i][1]-w[k][1]) + 2*abs(w[i][2]-w[k][2]) + abs(w[i][3]-w[k][3]) + abs(w[i][4]-w[k][4]) +
                                 abs(w[i][5]-w[k][5]) +   abs(w[i][6]-w[k][6]) +   abs(w[i][7]-w[k][7]) + abs(w[i][8]-w[k][8]) + abs(w[i][9]-w[k][9]) ;

                         /* dist += abs(w[i][m]-w[k][m]) ; */
                         /* dist += (nofPCs-m)*abs(w[i][m]-w[k][m]) ; */
                         /* dist += (nofPCs-m-1>0?nofPCs-m-1:1)*abs(w[i][m]-w[k][m]) ; */
                         
                         /* if ( dist <= cut ) */ 
                        
                        if ( dist < 10 )
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
                if ( added == 1 )
                    fprintf(stderr, "Added %6d member  to cluster %3d\n", added, current );
                else
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

