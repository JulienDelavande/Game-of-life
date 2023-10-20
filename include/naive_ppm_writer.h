/**
 * @file naive_ppm_writer.h
 *
 * @brief Fonction to generate images
 * 
 * @author Julien Delavande
 *
 * This is a fonction to generate a ppm image from a given universe.
 *
 * The API of the naive_load.h is defined as follows:
 *
 * - a function to generate a ppm image from a given universe
 */

# ifndef NAIVE_PPM_WRITER_H
# define NAIVE_PPM_WRITER_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"


/**
 * @brief Generate a ppm image from a given universe
 *
 * @param universe the universe to generate an image from
 * @param num the number of the file for the universe to be put in
 * 
 * @post create a img-num.ppm file in the out directory filed with a pictured version of the given universe
 */
void naive_generate_image(Uni universe, int num);


# endif