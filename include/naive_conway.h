/**
 * @file naive_conway.h
 *
 * @brief Fonctions about the simulation of the conways rules applied on the universe structure
 *
 * @author Julien Delavande
 *
 * This are fonctions about the simulation of the conway game of life applied on a universe structure.
 * They are two different implementations, on considering the universe is a torus [torus implementation]. They can be recognize with _torus word.
 * The other implementation considers that the cell outside of the universe are dead and can't born [outside-dead implementation].
 * The implementation wich will be used in further files is the torus one.
 *
 * The API of the naive_conway.h is defined as follows:
 *
 * - a function that apply the Conway's rules once on a given universe [outside-dead implementation]
 * - a function that apply the Conway's rules the number of steps of the universe [outside-dead implementation]
 * - a function that apply the Conway's rules once on a given universe [torus implementation]
 * - a function that apply the Conway's rules the number of steps of the universe [torus implementation]
 * - a function to test if a cell is alive
 * - a function to compte the number of cells alive around a given cell [outside-dead implementation]
 * - a function to compte the number of cells alive around a given cell [torus implementation]
 */

#ifndef NAIVE_CONWAY_H
#define NAIVE_CONWAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "naive_universe.h"
#include "../include/naive_ppm_writer.h"


/**
 * @brief Apply the Conway's rules once on a given universe [outside-dead implementation]
 *
 * @param p_universe a pointer to the universe 
 * 
 * @post the universe is modified : one step of Conway's is done
 */
void naive_step(Uni * p_universe);


/**
 * @brief Apply the Conway's rules the number of steps of the universe on a given universe [outside-dead implementation]
 *
 * @param p_universe a pointer to the universe
 * @param print_term a boolean true if you want to display the universe at all steps in the terminal  
 * @param print_ppm a boolean true if you want to create ppm files at all steps in the out directory  
 * 
 * @post the universe is modified :  the number of step of Conway's have been done
 */
void naive_simulation(Uni * p_universe, bool print_term, bool print_ppm);


/**
 * @brief Apply the Conway's rules once on a given universe [torus implementation]
 *
 * @param p_universe a pointer to the universe 
 * 
 * @post the universe is modified : one step of Conway's is done
 */
void naive_step_torus(Uni * p_universe);


/**
 * @brief Apply the Conway's rules the number of steps of the universe on a given universe [torus implementation]
 *
 * @param p_universe a pointer to the universe
 * @param print_term a boolean true if you want to display the universe at all steps in the terminal  
 * @param print_ppm a boolean true if you want to create ppm files at all steps in the out directory  
 * 
 * @post the universe is modified :  the number of step of Conway's have been done
 */
void naive_simulation_torus(Uni * p_universe, bool print_term, bool print_ppm);


/**
 * @brief Test if a cell is alive
 *
 * @param cell_char a character wich define the state of a cell
 * 
 * @return true if the cell is alive and false if not
 */
bool test_alive(char cell_char);


/**
 * @brief Compte the number of cells alive around a given cell [outside-dead implementation]
 *
 * @param last_universe a copy of the last universe
 * @param line the line of the cell to compte the number of alive neighbors
 * @param column the column of the cell to compte the number of alive neighbors
 * 
 * @return the number of alive cell around the given cell
 */
int compte_alive(Uni last_universe, int line, int column);


/**
 * @brief Compte the number of cells alive around a given cell [torus implementation]
 *
 * @param last_universe a copy of the last universe
 * @param line the line of the cell to compte the number of alive neighbors
 * @param column the column of the cell to compte the number of alive neighbors
 * 
 * @return the number of alive cell around the given cell
 */
int compte_alive_torus(Uni last_universe, int line, int column);


#endif