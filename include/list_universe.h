/**
 * @file list_universe.h
 *
 * @brief Simple definition of the structure Uni_l with fonctions
 *
 * @author Julien Delavande
 *
 * This is a definition of the structure Uni_l which represent a universe.
 * It contains the size of the universe, the number of steps and a linked list 
 * containing the alive or last alive cells of the universe.
 *
 * The API of the list_universe.h is defined as follows:
 *
 * - a function to print the universe
 * - a fonction to desalocate the universe
 * - a fonction to restructure the universe by shifting the cell and expensing the universe if needed
 * - a fonction to give the curent bounds of the universe according to the given list
 */

#ifndef LIST_UNIVERSE_H
#define LIST_UNIVERSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"


/**
 * @brief The structure representing the universe (containing a linked_list)
 */
struct Universe_list{
    //the number of steps
    int steps;
    //the width of the universe to display
    int width;
    //the height of the universe to display
    int height;
    //a pointer to a linked list containing the cells that could be alive
    Linked_list_cell * p_list;
};

/**
 * @brief An alias to the universe structure : Uni_l
 */
typedef struct Universe_list Uni_l;

/**
 * @brief Display the universe in the terminal
 *
 * @param universe  the universe to display
 *
 */
void print_universe_list(Uni_l universe);


/**
 * @brief Desalocate the universe list
 *
 * @param universe the universe to desalocate
 * 
 * @post the universe linked list has been desalocated
 */
void desalocate_universe(Uni_l universe);

/**
 * @brief Restructure the universe by shifting the cell and expensing the universe if needed
 *
 * @param p_universe a pointer to the universe to restructure
 * 
 * @post the universe has been restructure if needed
 */
void restruct_universe(Uni_l * p_universe);


/**
 * @brief Give the curent bounds of the universe according to the given list
 *
 * @param p_x_end a pointer to the previous maximal value of the x axes (maximum number of collumns = universe.width)
 * @param p_y_end a pointer to the previous maximal value of the y axes (maximum number of lines = universe.height)
 * @param p_x_begin a pointer to the previous minimal value of the x axes (0)
 * @param p_y_begin a pointer to the previous minimal value of the y axes (0)
 * @param list the list to evaluate the values in
 * 
 * @post the new bounds of the universe has been put in the variables pointed by the pointers
 * 
 * @return 0 if the bounds hasn't change and 1 instead
 */
int new_bounds(int * p_x_end, int * p_y_end, int * p_x_begin, int * p_y_begin, Linked_list_cell list);


#endif