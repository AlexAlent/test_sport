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

SPORTSMAN *str_to_sportsman( char *buf ) ;

void delete_sportsman( SPORTSMAN *S ) ;

int input_from_kbd( SPORTSMAN ***pA, size_t *pnA ) ;

void delete_all_sportsmen( SPORTSMAN **A, size_t nA ) ;

size_t select_best( SPORTSMAN **A, size_t nA ) ;

void sort_1( SPORTSMAN **A, size_t nA ) ;

#endif /* SPORT_H */
