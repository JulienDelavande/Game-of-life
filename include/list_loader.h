/**
 * @file list_loader.h
 *
 * @brief  This is a fonction to load a universe from a txt file or to print a given universe in a txt file.
 *
 * @author Julien Delavande
 *
 * This fonction load the universe alive cells in a linked list and the size and steps in the 
 * universe structure. 
 *
 * The API of the list_loader.h is defined as follows:
 *
 * - a function to load a universe from a txt file
 */

#ifndef LIST_LOADER_H
#define LIST_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"

/**
 * @brief Load the universe from a given txt file
 *
 * @param p_universe a pointer to the universe to modified with the txt version
 * @param file_name the path of the txt to load the universe of
 * 
 * @post modified the given universe by implementing the one in txt given file
 */
void load_list_txt (Uni_l * p_universe, char * file_name);

#endif