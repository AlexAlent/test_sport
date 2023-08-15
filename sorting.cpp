#include <stdio.h>
#include <string.h>
#include "sport.h"


int cmp_result( SPORTSMAN *A, SPORTSMAN *B ){
    if ( A->Result < B->Result ) {
        return -1 ;
    }
    if ( A->Result > B->Result ) {
        return 1 ;
    }
    return 0 ;
}

int cmp_familia( SPORTSMAN *A, SPORTSMAN *B ){
    return strcmp( A->Familia, B->Familia );
}

size_t select_best( SPORTSMAN **A, size_t nA, CMPFUNC func ){
    size_t R = 0 ;
    size_t k = 0 ;
    for ( k = 1; k < nA; k++ ) {
        if ( func( A[k], A[R] ) < 0 ) {
            R = k ;
        }
    }
    return R ;
}


/* Сортировка выбором */
void sort_1( SPORTSMAN **A, size_t nA, CMPFUNC func ){
    
    size_t k ;
    
    for ( k = 0; k < nA-1; k++ ) {
        size_t B = select_best( A+k, nA-k, func ) + k ;
        SPORTSMAN *S = A[k] ;
        A[k] = A[B] ;
        A[B] = S ;
    }
}
