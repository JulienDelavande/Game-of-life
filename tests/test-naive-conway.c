# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <assert.h>
# include <string.h>
# include <time.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"
# include "../include/naive_conway.h"

//creation of the fonction delay to create a loading barre (just estetic)
void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

//creation of a fonction which verify if a solution file corresponds to a conway generated universe
void verify_naive_conway(int number){
    char name_of_file_test[256];
    char name_of_file_sol[256];

    if (number < 10 ){
        sprintf(name_of_file_test, "./data/data/test-00%d.txt", number);
        sprintf(name_of_file_sol, "./data/data/test-00%d-sol.txt", number);
    }

    else if (number < 100){
        sprintf(name_of_file_test, "./data/data/test-0%d.txt", number);
        sprintf(name_of_file_sol, "./data/data/test-0%d-sol.txt", number);       
    }

    else {
        sprintf(name_of_file_test, "./data/data/test-%d.txt", number);
        sprintf(name_of_file_sol, "./data/data/test-%d-sol.txt", number); 
    }

    Uni universe_test;
    load_universe_txt(&universe_test, name_of_file_test);

    Uni universe_sol;
    load_universe_txt(&universe_sol, name_of_file_sol);
    naive_step_torus(&universe_test);
    assert(strcmp(universe_sol.matrice, universe_test.matrice) == 0 );

    free_uni(universe_sol);
    free_uni(universe_test);
}

//testing all files
int main(void){
    printf("=> TEST OF NAIVE_CONWAY\n");

    for (int i = 0; i < 512; i++){
        verify_naive_conway(i);
        delay(3);
        if (i%5 == 0){
            printf("|");
        }
    }
    printf("\n=> NAIVE_CONWAY OK\n");
    return 0;
}