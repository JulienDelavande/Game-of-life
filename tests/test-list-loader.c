#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"

int main(void){

    printf("--- TESTING LIST_LOADER FONCTIONS\n");

    //loading of the universe glider.txt
    Uni_l universe;
    load_list_txt(&universe, "./data/glider.txt");

    //testing if the universe is well load
    assert(universe.steps == 10);
    assert(universe.width == 20);
    assert(universe.height == 21);
    print_list(*(universe.p_list));
    print_universe_list(universe);

    //desalocation of the universe
    desalocate_universe(universe);

    printf("==> LIST_LOADER OK !\n");

    return 0;
}