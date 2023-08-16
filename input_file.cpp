#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sport.h"


int input_from_file( const char *filename, SPORTSMAN ***pA, size_t *pnA ){
    
    int Result = 0 ;
    size_t k = 0 ;
    size_t N = 0 ;
    FILE *src = 0 ;
    
    src = fopen( filename, "rt" ) ;
    if ( ! src ) {
        fprintf( stderr, "Cannot open file %s\n", filename );
        Result = 201 ;
        goto END ;
    }
    
    {
        /* Количество спортсменов из первой строчки файла */
        char buffer[128] ;
        fgets( buffer, sizeof(buffer), src ) ;
        N = atoi(buffer) ;
    }
    
    *pA = (SPORTSMAN**)malloc(N * sizeof(SPORTSMAN*)) ;
    if ( ! *pA ) {
        fprintf( stderr, "Out of memory (3)\n" ) ;
        Result = 202 ;
        goto END1 ;
    }
    memset( *pA, 0, N * sizeof(SPORTSMAN*)) ;
    *pnA = 0 ; // Количество фактически введенных спортсменов
    
    for ( k = 1; *pnA < N && !feof(src); k++ ) { // k - номер строки файла
        char buffer[16*1024] ;
        fgets( buffer, sizeof(buffer), src ) ;
        if ( buffer[0] == '#' ) {
            continue;
        }
        (*pA)[*pnA] = str_to_sportsman( buffer ) ;
        if ( ! (*pA)[*pnA] ) {
            continue ;
        }
        (*pnA)++ ;
    }
    
    goto END1 ;
    
    
END1:
    fclose( src );
    
END:
    return Result ;
}
