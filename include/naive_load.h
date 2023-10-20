/**
 * @file naive_load.h
 *
 * @brief Fonctions that load a universe from a txt and print a given universe in a txt file 
 * 
 * @author Julien Delavande
 *
 * This are fonction to load a universe from a txt file or to print a given universe in a txt file.
 *
 * The API of the naive_load.h is defined as follows:
 *
 * - a function to print the universe in a given file
 * - a function to load the universe from a given txt file
 */

#ifndef NAIVE_LOAD_H
#define NAIVE_LOAD_H


#include <stdio.h>
#include <stdlib.h>
#include "naive_universe.h"

/**
 * @brief Print the universe in a given file
 *
 * @param universe the universe to print in the txt file
 * @param string_file the path of the txt to print the universe in
 * 
 * @post create or modified the txt given file and filed it with the given universe
 */
void print_universe_txt(Uni universe, char * string_file);


/**
 * @brief Load the universe from a given txt file
 *
 * @param p_universe a pointer to the universe to modified with the txt version
 * @param string_file the path of the txt to load the universe of
 * 
 * @post modified the given universe by implementing the one in txt given file
 */
void load_universe_txt(Uni * p_universe, char * string_file);



#endif