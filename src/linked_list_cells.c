#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"

//creation of the the nil fonction which change the value of a pointer to NULL
Linked_list_cell nil(void){
    return NULL; 
}

//creation of the fonction cons which add a cell to the list at the beguining
void cons(Linked_list_cell * p_list, bool alive, int l, int c){
    Linked_list_cell p_next_cell = *p_list;
    *p_list = malloc(sizeof(Cell));
    (*p_list)->alive = alive;
    (*p_list)->l = l;
    (*p_list)->c = c;
    (*p_list)->next = p_next_cell;
}


//creation of the fonction size which return the size of the list
int size(Linked_list_cell list){
    Cell * p_next_cell = list;
    int i = 0;
    while (p_next_cell != NULL){
        i++;
        p_next_cell = p_next_cell->next;
    }
    return i;
}

//creation of a fonction which return the cell of the given place
Cell * get_element(Linked_list_cell list, int rank){
    int i = 0;
    while( i < rank){
        list = list->next;
        i++;
    }
    return list;
}

//creation of the fonction is_empty which return true if the list is empty and false if not
bool is_empty(Linked_list_cell list){
    if (list == NULL){
        return true;
    }
    return false;
}

//creation of the fonction insert which insert an element in the given position in the given list
void insert(Linked_list_cell * p_list, bool alive, int l, int c, int pos){
    int size_ = size(*p_list);
    if (pos>size_){
        printf("the given indice is bigger than the size of the list : position=%d > size=%d\n", pos, size_);
        return;
    }
    if (pos == 0){
        cons(p_list, alive, l, c);
        return;
    }
    int j = 1; 
    Linked_list_cell p_last_cell = *p_list;
    while ( j < pos){
        p_last_cell = p_last_cell->next;
        j++;
    }
    Linked_list_cell p_next_cell = p_last_cell->next;
    p_last_cell->next = malloc(sizeof(Cell));
    p_last_cell->next->alive = alive;
    p_last_cell->next->l = l;
    p_last_cell->next->c = c;
    p_last_cell->next->next = p_next_cell;
}

//creation of the fonction remove which remove an element in a given position from the given list
void remove_list(Linked_list_cell * p_list, int pos){
    if (pos == 0){
        Cell * p_old_cell = *p_list;
        *p_list = (*p_list)->next;
        free(p_old_cell);
        return;
    }
    int j = 1;
    Cell * p_next_cell = *p_list;
    while ( j < pos){
        p_next_cell = p_next_cell->next;
        j++;
    }
    Cell * p_old_cell = p_next_cell->next;
    p_next_cell->next = p_next_cell->next->next;
    free(p_old_cell);
}

//creation of the fonction desalocate which desalocate a list
void desalocate(Linked_list_cell * p_list){
    int size_l = size(*p_list);
    for (int i = 0; i < size_l; i++){
        remove_list(p_list, 0);
    }
    /*
    Cell * last_cell = NULL;
    Linked_list_cell list = *p_list;
    
    while (list != NULL){
        last_cell = list;
        list = list->next;
        print_list(last_cell);
        free(last_cell);

        print_list(last_cell);
    }
    *p_list = NULL;
    **/
}

//a fonction to remove the dead cell of the list
void remove_dead(Linked_list_cell * p_list){
    if (is_empty(*p_list)){
        return;
    } 
    while (!is_empty(*p_list)&&(*p_list)->alive == false){
        remove_list(p_list, 0);
    }

    if (is_empty(*p_list)){
        return;
    } 
    Cell * p_last_cell = *p_list;
    Cell * p_cur_cell = NULL;

    while (p_last_cell->next != NULL){
        if (p_last_cell->next->alive == false){
            p_cur_cell = p_last_cell->next;
            p_last_cell->next = p_last_cell->next->next;
            free(p_cur_cell);
        }
        else{
            p_last_cell = p_last_cell->next;
        }
    }
}

//creation of the fonction print_list which print the given list
void print_list(Linked_list_cell list){
    printf("[");
    while ( list != NULL){
        if (list->alive){
            printf(" (%d,%d)=>ALIVE,", list->l, list->c);
        }
        else{
            printf(" (%d,%d)=>DEAD,", list->l, list->c);
        }
        list = list->next;
    }
    printf("] \n");
}

//creation of a fonction wich compare two cells : return true if the first is before the second

bool compare_cell(Cell cell_1, Cell cell_2){
    if (cell_1.l < cell_2.l){
        return true;
    }
    if (cell_1.l > cell_2.l){
        return false;
    }
    if (cell_1.c <= cell_2.c){
        return true;
    }
    return false;
}
//creation of a fonction which sort the list
Linked_list_cell fusion_sort(Linked_list_cell list){
    if (list == NULL){
        return list;
    }
    int l_size = size(list);
    if ( l_size == 1){
        return list;
    }
    Linked_list_cell *  p_two_list = cut_list_two(list);    
    Linked_list_cell list_1 = fusion_sort(*p_two_list);
    Linked_list_cell list_2 = fusion_sort(*(p_two_list+1));

    Linked_list_cell new_list;
    Linked_list_cell * p_new_list = &new_list;
    new_list = nil();
    bool test = false;
    Cell * p_next_cell_list_1 = list_1;
    Cell * p_next_cell_list_2 = list_2;
    int i = 0;

    while ((p_next_cell_list_1 != NULL)&&(p_next_cell_list_2 != NULL)){
        test = compare_cell(*p_next_cell_list_1, *p_next_cell_list_2);
        
        if (test){
            insert(p_new_list, p_next_cell_list_1->alive, p_next_cell_list_1->l, p_next_cell_list_1->c, i);
            p_next_cell_list_1 = p_next_cell_list_1->next;
        }
        else{
            insert(p_new_list, p_next_cell_list_2->alive, p_next_cell_list_2->l, p_next_cell_list_2->c, i);
            p_next_cell_list_2 = p_next_cell_list_2->next;
        }
        i++;
    }
    if (p_next_cell_list_1 == NULL){
        while (p_next_cell_list_2 != NULL){
            insert(p_new_list, p_next_cell_list_2->alive, p_next_cell_list_2->l, p_next_cell_list_2->c, i);
            p_next_cell_list_2 = p_next_cell_list_2->next;
            i++;          
        }
    }
    if (p_next_cell_list_2 == NULL){        
        while (p_next_cell_list_1 != NULL){
            insert(p_new_list, p_next_cell_list_1->alive, p_next_cell_list_1->l, p_next_cell_list_1->c, i);
            p_next_cell_list_1 = p_next_cell_list_1->next; 
            i++;  
        }
    }
    //Linked_list_cell new_list = *p_new_list;
    
    desalocate(&list_1);
    desalocate(&list_2);
    free(p_two_list);

    return new_list;
}

//creation of a fonction which cut a list in two : return a pointer to the two list (mmalloc)

Linked_list_cell * cut_list_two(Linked_list_cell list){
    Linked_list_cell * p_two_list = malloc(2*sizeof(Linked_list_cell ));
    int l_size = size(list);
    *p_two_list = list;
    int c_size = 0;
    if (l_size%2 == 0){
        c_size = l_size/2;
    }
    else{
        c_size = (l_size +1)/2;
    }
    *(p_two_list + 1) = get_element(list, c_size);
    get_element(list, c_size-1)->next = NULL;

    return p_two_list;
}

//fonction that says if a cell is already in the list
bool is_in_list(Linked_list_cell list, int l, int c){
    while(list != NULL){
        if ((list->c == c)&&(list->l == l)){
            return true;
        }
        list = list->next;
    }
    return false;
}
