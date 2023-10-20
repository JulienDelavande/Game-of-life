/**
 * A simple program to load a universe txt file and prints it in the console
 *
 * Ex. of usage:
 *
 * ./app-list-loader ./data/glider.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"

int main(int argc, char *argv[]){

    //declaring a universe
    Uni_l universe;

    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }
    //load the universe from the file
    load_list_txt(&universe, argv[1]);

    //print the universe on the terminal
    print_universe_list(universe);

    //free the memory
    desalocate_universe(universe);

    return 0;
}