#ifndef SPORT_H
#define SPORT_H

#include <stdio.h>

#define FAMSIZE 30

struct sportsman_s {
    int Number ;
    char Familia[FAMSIZE] ;
    double Result ;
} ;

typedef struct sportsman_s SPORTSMAN ;

typedef int (*CMPFUNC)(SPORTSMAN*, SPORTSMAN*) ;

SPORTSMAN *str_to_sportsman( char *buf ) ;

void delete_sportsman( SPORTSMAN *S ) ;

int input_from_kbd( SPORTSMAN ***pA, size_t *pnA ) ;

void delete_all_sportsmen( SPORTSMAN **A, size_t nA ) ;

size_t select_best( SPORTSMAN **A, size_t nA, CMPFUNC func ) ;

void sort_1( SPORTSMAN **A, size_t nA, CMPFUNC func ) ;

int cmp_result( SPORTSMAN *A, SPORTSMAN *B ) ;

int cmp_familia( SPORTSMAN *A, SPORTSMAN *B ) ;

int input_from_file( const char *filename, SPORTSMAN ***pA, size_t *pnA ) ;


#endif /* SPORT_H */
