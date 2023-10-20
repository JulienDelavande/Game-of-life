/**
 * @file list_ppm_writer.h
 *
 * @brief Fonction to generate images
 *
 * @author Julien Delavande
 *
 * This is a fonction to generate a ppm image from a given universe.
 *
 * The API of the linked_list_cell.h is defined as follows:
 *
 * - a function to generate a ppm image from a given universe
 */

#ifndef LIST_PPM_WRITER_H
#define LIST_PPM_WRITER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"


/**
 * @brief Generate a ppm image from a given universe
 *
 * @param universe the universe to generate an image from
 * @param num the number of the file for the universe to be put in
 * 
 * @post create a img-num.ppm file in the out directory filed with a pictured version of the given universe
 */
void generate_ppm_list(Uni_l universe, int num);



#endif