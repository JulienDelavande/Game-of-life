# include <stdio.h>
# include <stdlib.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"


// fonction that takes a universe and print it the universe_data.txt file
void print_universe_txt(Uni universe, char * string_file){
    FILE * p_file = fopen(string_file, "w");
    int width = universe.width;
    int height = universe.height;
    int step = universe.step;
    char * mat = universe.matrice;
    fprintf(p_file, "%d %d \n%d", width, height, step);

    for (int i = 0; i < height; i++){
        fprintf(p_file, "\n");
        for (int j = 0; j < width; j++){
            fprintf(p_file, "%c", *(mat + i*width +j));
        }
    }
    fclose(p_file);
}



// fonction that modify a universe considering a given txt file
void load_universe_txt(Uni * p_universe, char * string_file){
    FILE * p_file = NULL;
    p_file = fopen(string_file, "r");
    int width = 0;
    int height = 0;
    int step = 0;
    int fscanf_result = 0;
    int line_nb = 1;
    char uni_char = '.';
    
    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", string_file);
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
    p_universe->step = step;
    line_nb++;

    //creation of the matrix
    p_universe->matrice = malloc( (width*height+1)*sizeof(char) );

    fscanf_result = fscanf(p_file,"%c", &uni_char);
    int i = 0;
    while (fscanf_result != EOF){
        if (fscanf_result != 1) {
            fprintf(stderr, "Line number %d is not syntactically correct!\n", line_nb);
            exit(EXIT_FAILURE);
        }
        if ((uni_char == '.')||(uni_char == 'o')){
            *(p_universe->matrice + i) = uni_char;
            i++;
        }
        fscanf_result = fscanf(p_file,"%c", &uni_char); 
    }   
    *(p_universe->matrice + height*width) = '\0';

    fclose(p_file);
}


