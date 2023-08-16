#include <stdlib.h>
#include <stdio.h>
#include "sport.h"


int main(int argc, char *argv[]){
    
    int Result = 0 ;
    SPORTSMAN **People = 0 ;
    size_t nPeople = 0 ;
    
    Result = input_from_file( "data.txt", &People, &nPeople ) ;
    if ( Result != 0 ) {
        return 1 ;
    }
    
    sort_1( People, nPeople, cmp_result ) ;
    
    {
        size_t k = 0 ;
        for ( k = 0; k < nPeople; k++) {
            printf( "%d,%s,%lf\n",
                   People[k]->Number,
                   People[k]->Familia,
                   People[k]->Result ) ;
        }
    }
    
    delete_all_sportsmen( People, nPeople ) ;
    
    return 0;
}
