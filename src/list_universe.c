#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"


//creation of a focntion to print the universe
void print_universe_list(Uni_l universe){
    Cell * p_cur_cell = *(universe.p_list);
    printf("\n");
    for (int i = 0; i < universe.height; i++){
        for (int j = 0; j < universe.width; j++){
           if ((!is_empty(*(universe.p_list)))&&(p_cur_cell->l == i)&&(p_cur_cell->c == j)){
               printf(" o");
               if (p_cur_cell->next != NULL){
                   p_cur_cell = p_cur_cell->next;
               }
           }
           else{
               printf(" .");
           }
        }
        printf("\n");
    }
}


//creation of a fonction to desalocate the universe (freed the memorie)
void desalocate_universe(Uni_l universe){
    desalocate(universe.p_list);
    free(universe.p_list);
}


//resize the universe
void restruct_universe(Uni_l * p_universe){
    Linked_list_cell * p_list = p_universe->p_list;
    int x_begin = 0;
    int y_begin = 0;
    int x_end = p_universe->width - 1;
    int y_end = p_universe->height - 1;
    if (new_bounds(&x_end, &y_end, &x_begin, &y_begin, *p_list) == 0)
        return;

    Cell * p_next_cell = *(p_universe->p_list);
    int inc_x = - x_begin;
    int inc_y = - y_begin;
    while (p_next_cell != NULL){
        p_next_cell->c = p_next_cell->c + inc_x;
        p_next_cell->l = p_next_cell->l + inc_y;
        p_next_cell = p_next_cell->next;
    }
    p_universe->height = y_end + inc_y + 1;
    p_universe->width = x_end + inc_x + 1;



}

//return 0 if nothing has change
int new_bounds(int * p_x_end, int * p_y_end, int * p_x_begin, int * p_y_begin, Linked_list_cell list){
    int x_begin = *p_x_begin;
    int x_end = *p_x_end;
    int y_begin = *p_y_begin;
    int y_end = *p_y_end;

    while (list != NULL){
        if (x_begin > list->c){
            x_begin = list->c;
        }
        if (x_end < list->c){
            x_end = list->c;
        }
        if (y_begin > list->l){
            y_begin = list->l;
        }
        if (y_end < list->l){
            y_end = list->l;
        }
        list = list->next;

    }
    if((x_begin == *p_x_begin)&&(y_begin == *p_y_begin)&&(x_end == *p_x_end)&&(y_end == *p_y_end))
        return 0;

    *p_x_begin = x_begin;
    *p_y_begin = y_begin;
    *p_y_end = y_end;
    *p_x_end = x_end;

    return 1;
    

    
    
}