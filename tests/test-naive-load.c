#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/naive_universe.h"
#include "../include/naive_load.h"


int main(void){
    
    printf("=> TEST OF NAIVE_LOAD \n\n");

    //creation of a txt file according to a universe structure
    printf("---testing of print_universe_txt fonction \n");
    Uni universe = {10, 10, 4};
    set_universe_null(&universe);
    set_alive(&universe, 0, 0);
    print_universe_txt(universe, "./data/universe_data.txt");
    free_uni(universe);
    printf("---print_universe_txt fonction OK\n");

    //implementation of a txt file universe into a universe structure and testing if it is well did.
    printf("---testing of load_universe_txt fonction \n");
    Uni universe_2;
    load_universe_txt(&universe_2, "./data/glider.txt");
    aff_uni(universe_2);
    assert(universe_2.height == 21);
    assert(universe_2.width == 20);
    assert(universe_2.step == 10);
    printf("height, width and step well implemented\n");
    
    char original_string[] = ".o....................o.................ooo.........................................................................................................................................................................................................................................................................................................................................................................................";
    assert(strcmp(universe_2.matrice, original_string) == 0);
    printf("matrice well implemented\n");
    free_uni(universe_2);
    printf("---load_universe_txt fonction OK\n");

    

    printf("\n=>NAIVE_LOAD OK\n");

    return 0;
}