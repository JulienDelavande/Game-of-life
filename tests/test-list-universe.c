#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"

int main(void){


    printf("TESTING LIST_UNIVERSE FONCTIONS\n");

    //creation of a list by hand and sorting it
    Linked_list_cell list = nil();
    cons(&list, true, 1, 1);
    cons(&list, true, 2, 1);
    insert(&list, true, 5, 7, 0);
    insert(&list, true, 4, 9, 2);
    insert(&list, true, 5, 6, 2);
    list = fusion_sort(list);

    //creation of a universe by hand
    Uni_l universe ={5, 12, 14};
    universe.p_list = malloc(sizeof(Linked_list_cell));
    assert(universe.steps == 5);
    assert(universe.width == 12);
    assert(universe.height == 14);
    *(universe.p_list) = list;
    printf(" -> display of the list \n");
    print_list(list);

    //testing the print_universe fonction and the desalocate fonction
    printf(" -> display of the universe");
    print_universe_list(universe);
    desalocate_universe(universe);

    //testing the expense of the universe
    printf("\n --- testing the expense of the universe --- \n");
 
    //creation of a list by hand and sorting it
    Linked_list_cell list_2 = nil();
    cons(&list_2, true, 1, -5);
    cons(&list_2, true, -2, 9);
    insert(&list_2, true, 5, 14, 1);
    insert(&list_2, true, 15, 9, 2);
    insert(&list_2, true, 5, 6, 2);
    list_2 = fusion_sort(list_2);
    printf(" -> display of the list before restructuration\n");
    print_list(list_2);

    //creation of a universe by hand
    Uni_l universe_2 = {8, 12, 14};
    universe_2.p_list = malloc(sizeof(Linked_list_cell));
    *(universe_2.p_list) = list_2;
    restruct_universe(&universe_2);
    printf(" -> display of the list after restructuration\n");
    print_list(*universe_2.p_list);
    assert(universe_2.steps == 8);
    assert(universe_2.width == 20);
    assert(universe_2.height == 18);

    printf(" -> display of the universe expensed");
    print_universe_list(universe_2);
    desalocate_universe(universe_2);

    printf("==> LIST_UNIVERSE OK !");

    return 0;
}