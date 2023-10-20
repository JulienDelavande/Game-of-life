#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"

//creation of the fonction that load a universe from a txt file
void load_list_txt (Uni_l * p_universe, char * file_name){
    FILE * p_file = NULL;
    p_file = fopen(file_name, "r");
    int width = 0;
    int height = 0;
    int step = 0;
    int fscanf_result = 0;
    char cell_char = '.';
    int line_nb = 0;
    
    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", file_name);
        exit(EXIT_FAILURE);
    }
    
    fscanf_result = fscanf(p_file,"%d %d", &width, &height);
    if (fscanf_result != 2) {
        fprintf(stderr, "Line number %d is not syntactically correct!\n", line_nb);
        exit(EXIT_FAILURE);
    }
    p_universe->width = width;
    p_universe->height = height;
    line_nb++;
    
    fscanf_result = fscanf(p_file,"%d", &step);
    if (fscanf_result != 1) {
        fprintf(stderr, "Line number %d is not syntactically correct!\n", line_nb);
        exit(EXIT_FAILURE);
    }
    p_universe->steps = step;
    line_nb++;

    (p_universe->p_list) = malloc(sizeof(Linked_list_cell));
    *(p_universe->p_list) = NULL;

    int i = 0;
    int l_size = 0;
    
    fscanf_result =  fscanf(p_file,"%c", &cell_char);
    while (fscanf_result != EOF){
        if (fscanf_result != 1) {
            fprintf(stderr, "Line number %d is not syntactically correct!\n", line_nb);
            exit(EXIT_FAILURE);
        }
        if (cell_char == '.'){
            i++;
        }
        if (cell_char == 'o'){
            insert(p_universe->p_list, true, i/width, i%width, l_size);
            l_size++;
            i++;
        }
         fscanf_result = fscanf(p_file,"%c", &cell_char);
    }
    fclose(p_file);
}