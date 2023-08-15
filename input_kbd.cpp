#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sport.h"


inline int is_uint( char *buf ){
    for ( ; *buf; buf++ ) {
        if ( ! isdigit(*buf) ) {
            return 0 ;
        }
    }
    return 1 ;
}

int input_from_kbd( SPORTSMAN ***pA, size_t *pnA ){
    
    int Result = 0 ;
    size_t k = 0 ;
    {
        /* Вводим количество спортсменов */
        char buffer[128] ;
        printf( "Amount of sportsmen: " ) ;
        fgets(buffer, sizeof(buffer), stdin) ;
        if ( is_uint( buffer ) ) {
            fprintf( stderr, "Invalid sportsmen count\n" ) ;
            goto END ;
        }
        *pnA = atoi(buffer) ;
    }
    
    *pA = (SPORTSMAN**)malloc(*pnA * sizeof(SPORTSMAN*)) ;
    if ( ! *pA ) {
        fprintf( stderr, "Out of memory (2)\n" ) ;
        Result = 101 ;
        goto END ;
    }
    memset( *pA, 0, *pnA * sizeof(SPORTSMAN*)) ;
    
    // goto END1 ;
    
    for ( k = 0; k < *pnA; k++ ) {
        char buffer[16*1024] ;
        fgets( buffer, sizeof(buffer), stdin ) ;
        (*pA)[k] = str_to_sportsman( buffer ) ;
        if ( ! (*pA)[k] ) {
            Result = 102 ;
            goto END2 ;
        }
    }
    
    return Result ;
    
END2:
    for ( k = 0; k < *pnA; k++ ) {
        if ( (*pA)[k] ) {
            delete_sportsman( (*pA)[k] ) ;
        }
    }
    
END1:
    free( *pA ) ;
    *pA = 0 ;
    *pnA = 0 ;
    
END:
    return Result ;
}


void delete_all_sportsmen( SPORTSMAN **A, size_t nA ){
    size_t k = 0 ;
    if ( A ) {
        for ( k = 0; k < nA; k++) {
            if ( A[k] ) {
                delete_sportsman( A[k] ) ;
            }
        }
        free( A ) ;
    }
}
