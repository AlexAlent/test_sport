#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sport.h"

/**
 * Размещает структуру типа SPORTSMAN и заполняет
 * её значениями, указанными в тексте buf.
 * Формат исходного текста:
 * 12,Иванов,99.01
 */
 

SPORTSMAN *str_to_sportsman( char *buf ){
    
    char *P = 0 ;
    SPORTSMAN *R = 0 ;
    
    R = (SPORTSMAN*)malloc(sizeof(SPORTSMAN)) ;
    if ( ! R ) {
        fprintf( stderr, "Out of memory (1)\n" ) ;
        goto END ;
    }
    memset( R, 0, sizeof(SPORTSMAN) ) ;
    
    /* номер */
    P = strchr( buf, ',' ) ;
    if ( ! P ) {
        fprintf( stderr, "Invalid data format (1)\n") ;
        goto END1 ;
    }
    *P = 0 ;
    R->Number = atoi(buf) ;
    buf = P+1 ;
    
    /* фамилия */
    P = strchr( buf, ',' ) ;
    if ( ! P ) {
        fprintf( stderr, "Invalid data format (2)\n") ;
        goto END1 ;
    }
    *P = 0 ;
    strncpy( R->Familia, buf, FAMSIZE-1 ) ;
    buf = P+1 ;
    
    /* результат */
    P = strchr(buf, ',' ) ;
    if ( P ) {
        fprintf( stderr, "Invalid data format (3)\n") ;
        goto END1 ;
    }
    R->Result = atof( buf ) ;
    
    return R ;
    
    
END1:
    free(R) ;
    
END:
    return 0 ;
    
}


void delete_sportsman( SPORTSMAN *S ){
    if (S) {
        free(S) ;
    }
}
