#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_conway.h"
#include "../include/list_ppm_writer.h"


//creation of a fonction that apply the conway rules on a universe once
void list_step (Uni_l * p_universe){
    Linked_list_cell * p_list= (p_universe->p_list);
    Cell * p_next_cell = *p_list;
    int nb_neig = 0;

    while (p_next_cell != NULL){
        nb_neig = nb_neighboor(*p_list, p_next_cell->l, p_next_cell->c);
        if (!list_rules(nb_neig, true)){
            p_next_cell->alive = false;
        }
        p_next_cell = p_next_cell->next;
    }
    
    p_next_cell = *p_list;

    Linked_list_cell list_new_cell = nil();

    int i = -1;
    int j = -1;
    while (p_next_cell != NULL){
        i = -1;
        while (i < 2){
            j = -1;
            while (j < 2){
                if (!((i == 0)&&(j == 0))){
                    nb_neig = nb_neighboor(*p_list, (p_next_cell->l)+i, (p_next_cell->c)+j);
                    if (list_rules(nb_neig, false)&&!is_in_list(list_new_cell, (p_next_cell->l)+i, (p_next_cell->c)+j)){
                        cons(&list_new_cell, true, (p_next_cell->l)+i, (p_next_cell->c)+j);
                    }
                }
                j++;
            }
            i++;
        }
       p_next_cell = p_next_cell->next; 
    }

    Linked_list_cell list_new_cell_begin = list_new_cell;

    remove_dead(p_list);
    while(list_new_cell != NULL){
        if(!is_in_list(*p_list, list_new_cell->l, list_new_cell->c)){
            cons(p_list, true, list_new_cell->l, list_new_cell->c);
        }
        list_new_cell = list_new_cell->next;

    }
    desalocate(&list_new_cell_begin);
    *p_list = fusion_sort(*p_list);

    restruct_universe(p_universe);
}



//creation of a fonction which return true if the cell will stay/become alive at the next step
bool list_rules(int nb_neig, bool alive){
    if (alive){
        if ((nb_neig == 2)||(nb_neig == 3)){
            return true;
        }
        return false;
    }
    if (nb_neig == 3){
        return true;
    }
    return false;
}

//creation of a fonction that compte the number of cells alive around a given cell
int nb_neighboor(Linked_list_cell list, int l, int c){
    int nb = 0;
    int i = -1;
    int j = -1;
    while (i < 2){
        j = -1;
        while (j < 2){
            bool test = !((i == 0)&&(j == 0));
            if (is_in_list(list, l+i, c+j)&&test){
                nb++;
            }
            j++;
        }
        i++;
    }
    return nb;
}

//creation of a fonction that apply the simulation to a universe and print each step in the terminal and create ppm images if wanted
void list_simulation(Uni_l * p_universe, bool print_term, bool print_ppm){
    int steps = p_universe->steps;
    if(print_term){
        printf("----- universe step 0 -----");
        print_universe_list(*p_universe);
    }
    if(print_ppm){
        generate_ppm_list(*p_universe, 0);
    }
    for (int i = 0; i < steps; i++){
        list_step(p_universe);
        if(print_term){
            printf("\n----- universe step %d -----", i+1);
            print_universe_list(*p_universe);
        }
        if(print_ppm){
            generate_ppm_list(*p_universe, i+1);
        }
    }
}