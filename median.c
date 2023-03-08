#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define     MAX_CLU         500000


int     dat[ MAX_CLU ][ 2 ];


int main()
{
    int     N = 0;
    int     start_idx, last_idx;
    int     i;

    while( scanf("%d %d", &dat[ N ][0], &dat[ N ][1] ) == 2 )
        N++;

    for ( i=dat[ 0 ][0] ; i <= dat[ N-1 ][0] ; i++ )
    {
        start_idx = -1;
        while ( dat[ start_idx ][0] != i && start_idx < N )
            start_idx++;

        if ( start_idx >=0 && start_idx < N )
        {
            last_idx = start_idx;
            while ( dat[ last_idx ][0] == i )
                last_idx++;

            last_idx--;

            if ( start_idx == last_idx )
                printf(" %d %d\n", dat[start_idx][0], dat[start_idx][1] );
            else if ( (last_idx - start_idx) % 2 == 0 )
                printf(" %d %d\n", dat[start_idx+(last_idx-start_idx)/2][0], dat[start_idx+(last_idx-start_idx)/2][1] );
            else
                printf(" %d %f\n", dat[start_idx+(last_idx-start_idx)/2][0], (dat[start_idx+(last_idx-start_idx)/2][1] + dat[start_idx+ 1 +(last_idx-start_idx)/2][1])/2.0  );

        }

    }

}

