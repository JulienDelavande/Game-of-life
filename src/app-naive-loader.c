/**
 * A simple program to load a universe txt file and prints it in the console
 *
 * Ex. of usage:
 *
 * ./app-naive-loader ./data/glider.txt
 */


#include <stdlib.h>
#include <stdio.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"

int main(int argc, char **argv){

    // testing if a filename has been given
    if (argc != 2) {
        fprintf(stderr, "You must provide a file name!\n");
        exit(EXIT_FAILURE);
    }

    Uni universe;
    FILE * p_file = NULL;

    p_file = fopen(argv[1], "r");

    if(p_file == NULL){
        fprintf(stderr, "cannot read file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    fclose(p_file);

    load_universe_txt(&universe, argv[1]);
    printf("Print of the universe from : %s \n", argv[1]);
    aff_uni(universe);

    free_uni(universe);



    return 0;
}
