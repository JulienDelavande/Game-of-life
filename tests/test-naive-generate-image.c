# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"
# include "../include/naive_ppm_writer.h"

int main(void){

    Uni universe;

    load_universe_txt(&universe, "./data/glider.txt");
    naive_generate_image(universe, 0);
    printf("image well generated \n");
    free_uni(universe);

    printf("=> NAIVE_GENERATE_IMAGE OK\n");

    return 0;
}