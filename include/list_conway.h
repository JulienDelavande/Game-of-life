/**
 * @file list_conway.h
 *
 * @brief Fonctions about the simulation of the conways rules applied on the universe structure
 *
 * @author Julien Delavande
 *
 * This are fonctions about the simulation of the conway game of life applied on a universe structure.
 * The universe could expend.
 * 
 *
 * The API of the linked_list_cell.h is defined as follows:
 *
 * - a function to apply the conways rules to a universe once
 * - a function to know what state of cell should be at next step
 * - a function to compte the number of alive cell around a given cell
 * - a function to apply a simulation on a given universe
 */

#ifndef LIST_CONWAY_H
#define LIST_CONWAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_ppm_writer.h"



/**
 * @brief Apply the Conway's rules once on a given universe
 *
 * @param p_universe a pointer to the universe 
 * 
 * @post the universe is modified : one step of Conway's is done
 */
void list_step(Uni_l * p_universe);


/**
 * @brief Know what state of cell should be at next step
 *
 * @param nb_neig the number of alive cells around the cell you want to have the future state
 * @param alive a boolean that is true if the cell to test the further state is curently alive
 * 
 * @return true if the cell will be alive in the next step according to conway's rules
 */
bool list_rules(int nb_neig, bool alive);


/**
 * @brief Compte the number of cells alive around a given cell
 *
 * @param list the list of the alive cell at current state
 * @param l the line of the cell to compte the number of alive neighbors
 * @param c the column of the cell to compte the number of alive neighbors
 * 
 * @return the number of alive cell around the given cell
 * 
 * @pre the cells in the list should all be alive cells
 */
int nb_neighboor(Linked_list_cell list, int l, int c);


/**
 * @brief Apply the Conway's rules the number of steps of the universe on a given universe
 *
 * @param p_universe a pointer to the universe
 * @param print_term a boolean true if you want to display the universe at all steps in the terminal  
 * @param print_ppm a boolean true if you want to create ppm files at all steps in the out directory  
 * 
 * @post the universe has been modified : the number of step of Conway's have been done
 */
void list_simulation(Uni_l * p_universe, bool print_term, bool print_ppm);

#endif