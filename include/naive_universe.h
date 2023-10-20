/**
 * @file naive_universe.h
 *
 * @brief Simple definition of the structure Uni with fonctions
 *
 * @author Julien Delavande
 *
 * This is a definition of the structure Uni which represent a universe.
 * It contains the size of the universe and a matrix filled with char to represent
 * the universe.
 *
 * The API of the naive_univer.h is defined as follows:
 *
 * - a function to get the value of the universe's matrix
 * - a function to set the universe matrix's cells dead
 * - a function to display the universe in the terminal
 * - a function to switch the value in its other state of a cells in the universe matrix
 * - a function to set a cell's universe matrix alive
 * - a function to set a cell's universe matrix dead
 * - a function to create a copy of a given universe
 * - a fonction to desalocate the universe matrix
 */

#ifndef NAIVE_UNIVERSE_H
#define NAIVE_UNIVERSE_H

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief The structure representing the universe
 */
struct Universe{
    // the heigh of the universe
    int height;
    //the width of the universe
    int width;
    // the number of steps that will happend
    int step;
    // a matrix of char representing the states of the cells in the universe
    char * matrice;
};

/**
 * @brief An alias to the universe structure : Uni
 */
typedef struct Universe Uni;


/**
 * @brief Get the value of the universe's matrix
 *
 * @param universe    the universe 
 * @param ligne     the ligne of the value you want to access
 * @param column     the column of the value you want to access
 *
 * @return the character of the given ligne and column of the universe matrix
 * 
 * @pre   `ligne` and `column`should be comprised between 0 and universe.height-1 and universe.width-1 respectively
 */
char access(Uni universe, int ligne, int column);

/**
 * @brief Set the universe matrix's cells dead
 *
 * @param p_universe  a pointer toward the universe to be modified
 *
 * @post After the call to `set_universe_null`, all cells of the universe matrix are set dead (contain the char '-')
 */
void set_universe_null(Uni * p_universe);

/**
 * @brief Display the universe in the terminal
 *
 * @param universe  the universe to display
 *
 */
void aff_uni(Uni universe);

/**
 * @brief Switch the value in its other state of a cells in the universe matrix
 *
 * @param p_universe  a pointer toward the universe to be modified
 * @param ligne     the ligne of the value you want to modified
 * @param column     the column of the value you want to modified
 *
 * @post After the call to `aff_uni`, the given cell of the universe matrix switch its value into the other state
 */
void switch_value(Uni * p_universe, int ligne, int colomn);

/**
 * @brief Set a cell's universe matrix alive
 *
 * @param p_universe  a pointer toward the universe to be modified
 * @param ligne     the ligne of the value you want to modified
 * @param column     the column of the value you want to modified
 *
 * @post After the call to `aff_uni`, the given cell of the universe matrix is set alive (the given cell contain the 'o' character)
 */
void set_alive(Uni * p_universe, int ligne, int colomn);


/**
 * @brief Set a cell's universe matrix dead
 *
 * @param p_universe  a pointer toward the universe to be modified
 * @param ligne     the ligne of the value you want to modified
 * @param column     the column of the value you want to modified
 *
 * @post After the call to `aff_uni`, the given cell of the universe matrix is set dead (the given cell contain the '.' character)
 */
void set_dead(Uni * p_universe, int ligne, int colomn);


/**
 * @brief Create a copy of a given universe
 *
 * @param universe the universe to copy
 * 
 * @return a copy of the universe
 */
Uni copy_uni(Uni universe);


/**
 * @brief Desalocate the universe matrix
 *
 * @param universe the universe to desalocate
 * 
 * @post the universe matrix is desalocated
 */
void free_uni(Uni universe);

#endif
