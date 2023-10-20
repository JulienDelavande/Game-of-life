#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../include/linked_list_cells.h"

int main(void){

    printf("---TESTING LINKED_LIST_CELLS FONCTIONS \n");

    // construction of a list by hand (testing nil and cons fonctions)
    printf("construction of a list by hand : expected one \n[(2,1)=>ALIVE, (1,1)=>ALIVE]\n");
    Linked_list_cell list = nil();
    cons(&list, true, 1, 1);
    cons(&list, true, 2, 5);

    // testing the print_list and size fonction
    print_list(list);
    printf("size = %d\n", size(list));
    assert(size(list)==2);

    // testing the insert fonction
    printf("insertion of new elements : expecting list\n[(5,7)=>DEAD, (2,1)=>ALIVE, (5,6)=>DEAD, (4,9)=>ALIVE, (1,1)=>ALIVE]\n");
    insert(&list, false, 5, 7, 0);
    insert(&list, true, 4, 9, 2);
    insert(&list, false, 5, 6, 2);
    print_list(list);

    //testing compare cell fonction
    assert(compare_cell(*list, *list));
    assert(!compare_cell(*list, *(list->next)));

    //testing the merge sort fonction 

    
    printf("sorting of the list : \n");
    list = fusion_sort(list);
    print_list(list);


    //testing remove dead fonction
    remove_dead(&list);
    printf("all the dead cells should has been removed : \n");
    print_list(list);

    //testing the remove fonction
    printf("remove of some elements : \n-> number 0 : \n");
    remove_list(&list, 0);
    print_list(list);
    remove_list(&list, 1);
    printf("-> number 1 : \n");
    print_list(list);

    //testing the desalocate fonction and is empty fonction
    assert(!is_empty(list));
    cons(&list, true, 1, 1);
    cons(&list, true, 5, 12);
    print_list(list);
    desalocate(&list);
    print_list(list);
    assert(is_empty(list));

    printf("==> LINKED_LIST_CELLS OK !");

    return 0;
}