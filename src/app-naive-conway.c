/**
 * A simple program to load a universe txt file apply the conway's step 
 * (prints it in the console if second argument of the fonction simulation is on true)  as well
 * as creating ppm images in the out directory
 *
 * Ex. of usage:
 *
 * ./app-naive-conway ./data/glider.txt
 */


# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"
# include "../include/naive_conway.h"
# include "../include/naive_ppm_writer.h"

int main(int argc, char * argv[]){

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

    naive_simulation_torus(&universe, true, true);
    free_uni(universe);



    return 0;
}