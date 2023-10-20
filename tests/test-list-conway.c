#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"
#include "../include/list_conway.h"

void test_list_uni(Uni_l universe_sol, Uni_l universe_test);

void verify_list_conway(int number);

void delay(int milliseconds);

int main(void){

    printf("=> TEST OF LIST_CONWAY\n");

    for (int i = 0; i < 512; i++){
        verify_list_conway(i);
        delay(2);
        if (i%5 == 0){
            printf("|");
        }
    }
    printf("\n=> LIST_CONWAY OK\n");
    return 0;
}

void test_list_uni(Uni_l universe_sol, Uni_l universe_test){
    Cell * p_next_cell_sol = *(universe_sol.p_list);
    Cell * p_next_cell_test = *(universe_test.p_list);
    while (p_next_cell_sol != NULL){
        assert((p_next_cell_sol->c == p_next_cell_test->c)&&(p_next_cell_sol->l == p_next_cell_test->l));
        p_next_cell_test = p_next_cell_test->next;
        p_next_cell_sol = p_next_cell_sol->next;
    }
    assert(p_next_cell_test == NULL);

}

void verify_list_conway(int number){
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


    Uni_l universe_test;
    load_list_txt(&universe_test, name_of_file_test);

    Uni_l
     universe_sol;
    load_list_txt(&universe_sol, name_of_file_sol);  
    list_step(&universe_test);

    test_list_uni(universe_sol, universe_test);

    desalocate_universe(universe_sol);
    desalocate_universe(universe_test);
}

//creation of the fonction delay to create a loading barre (just estetic)
void delay(int milliseconds){
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}