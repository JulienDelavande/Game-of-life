/**
 * A simple program to load a universe txt file apply the conway's step 
 * and to create ppm images in the out directory
 *(and it prints the universe at each step in the console as well if the second argument on list_simulation is on true)

 * Ex. of usage:
 *
 * ./app-list-conway ./data/glider.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"
#include "../include/list_conway.h"
#include "../include/list_ppm_writer.h"

int main(int argc, char *argv[]){

    //declaring an universe
    Uni_l universe;

    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }

    //loading the universe from the file
    load_list_txt(&universe,argv[1]);

    //creting images while doing the simulation
    list_simulation(&universe, false, true);

    //free the memory
    desalocate_universe(universe);

    return 0;
}