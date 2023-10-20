#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_ppm_writer.h"

//fonction that generates a ppm image of a universe and calls it by its number
void generate_ppm_list(Uni_l universe, int num){
    FILE * p_file = NULL;
    char file_name[256];
     
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

    Cell * p_cur_cell = *(universe.p_list);
    for (int i = 0; i < universe.height; i++){
        for (int j = 0; j < universe.width; j++){
           if ((!is_empty(*(universe.p_list)))&&(p_cur_cell->l == i)&&(p_cur_cell->c == j)){
               fprintf(p_file, "0   0   0   ");
               if (p_cur_cell->next != NULL){
                   p_cur_cell = p_cur_cell->next;
               }
           }
           else{
               fprintf(p_file, "255 255 255 ");
           }
        }
        fprintf(p_file,"\n");
    }
    fclose(p_file);
}