# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../include/naive_universe.h"
# include "../include/naive_ppm_writer.h"
# include "../include/naive_load.h"

//fonction that generates a ppm image of a universe and calls it by its number
void naive_generate_image(Uni universe, int num){
    FILE * p_file = NULL;
    char file_name[256];
    char uni_char = '.';
     
    if (num < 10){
        sprintf(file_name, "./out/img-00%d.ppm", num);
    }

    else if (num < 100){
        sprintf(file_name, "./out/img-0%d.ppm", num);
    }

    else {
        sprintf(file_name, "./out/img-%d.ppm", num);
    }

    p_file = fopen(file_name, "w");

    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", file_name);
        exit(EXIT_FAILURE);
    }

    fprintf(p_file, "P3\n%d %d\n255\n", universe.width, universe.height);
    for (int i = 0; i < universe.height; i++){
        for (int j = 0; j < universe.width; j++){
            uni_char = *(universe.matrice + i*universe.width +j);
            if (uni_char == '.'){
                fprintf(p_file,"255 255 255 ");
            }
            else {
                fprintf(p_file,"  0   0   0 ");
            }
            
        }
        fprintf(p_file,"\n");
    }
    fclose(p_file);
}