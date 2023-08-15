#include <stdio.h>
#include "sport.h"


size_t select_best( SPORTSMAN **A, size_t nA ){
    size_t R = 0 ;
    size_t k = 0 ;
    for ( k = 1; k < nA; k++ ) {
        if ( A[k]->Result < A[R]->Result ) {
            R = k ;
        }
    }
    return R ;
}


/* Сортировка выбором */
void sort_1( SPORTSMAN **A, size_t nA ){
    
    size_t k ;
    
    for ( k = 0; k < nA-1; k++ ) {
        size_t B = select_best( A+k, nA-k ) + k ;
        SPORTSMAN *S = A[k] ;
        A[k] = A[B] ;
        A[B] = S ;
    }
}
