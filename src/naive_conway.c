# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../include/naive_universe.h"
# include "../include/naive_load.h"
# include "../include/naive_conway.h"
# include "../include/naive_ppm_writer.h"

// fonction that test if a cell is alive
bool test_alive(char cell_char){
    if (cell_char == 'o'){
        return true;
    }
    return false;
}

// fonction that compte the number of cells alive arournd a given cell : it considers the cells outside of the matrix dead
int compte_alive(Uni last_universe, int line, int column){

    int compte = 0;
    bool test_borne = false;
    bool alive_test = false;

    for (int i = line-1; i < line +2; i++){
        for( int j = column-1; j < column +2; j++){
            test_borne = (((-1<i)&(i<last_universe.height))||((-1<j)&(j<last_universe.width)));
            alive_test = test_alive(*(last_universe.matrice + i*last_universe.width +j));
            if (test_borne&&alive_test){
                compte++;
            }
        }
    }
    if (test_alive(*(last_universe.matrice + line*last_universe.width + column))){
            compte--;
    }
    return compte;
}

// fonction that compte the number of cells alive arournd a given cell : it considers the universe as a torus
int compte_alive_torus(Uni last_universe, int line, int column){
    int compte = 0;
    int i_ = 0;
    int j_ = 0;
    for (int i = line-1; i < line +2; i++){
        for( int j = column-1; j < column +2; j++){
            i_ = i;
            j_ = j;
            if (j == -1){
                j_ = last_universe.width - 1;
            }
            if (i == -1){
                i_ = last_universe.height - 1;
            }
            if (test_alive(*(last_universe.matrice + (i_%last_universe.height)*last_universe.width +(j_%last_universe.width)))){
                compte++;
            }
        
            if (!test_alive(*(last_universe.matrice + (i_%last_universe.height)*last_universe.width +(j_%last_universe.width)))){
            }
        }
    }
    if (test_alive(*(last_universe.matrice + line*last_universe.width + column))){
            compte--;
    }
    return compte;
}

// fonction that modify the universe by appliing the rules of evolution once: it considers the cells outside of the matrix dead
void naive_step(Uni * p_universe){
    int width = p_universe->width;
    int height = p_universe->height;
    char uni_char = '.';
    int compte = 0;

    Uni last_universe = copy_uni(*p_universe);

    for (int i = 0; i<height; i++){
        for (int j = 0; j<width; j++){
            uni_char = *(last_universe.matrice + i*width +j);
            compte = compte_alive(last_universe, i, j);
            if ((uni_char == '.')&&(compte == 3)){
                *(p_universe->matrice + i*width +j) = 'o';
            }
            if ((uni_char == 'o')&&((compte != 3)&&(compte != 2))){
                *(p_universe->matrice + i*width +j) = '.';
            }
        }
    }
}

// fonction that modify the universe by appliing the rules of evolution once: it considers the universe as a torus
void naive_step_torus(Uni * p_universe){
    int width = p_universe->width;
    int height = p_universe->height;
    char uni_char = '.';
    int compte = 0;

    Uni last_universe = copy_uni(*p_universe);

    for (int i = 0; i<height; i++){
        for (int j = 0; j<width; j++){
            uni_char = *(last_universe.matrice + i*width +j);
            compte = compte_alive_torus(last_universe, i, j);
            if ((uni_char == '.')&&(compte == 3)){
                *(p_universe->matrice + i*width +j) = 'o';
            }
            if ((uni_char == 'o')&&((compte != 3)&&(compte != 2))){
                *(p_universe->matrice + i*width +j) = '.';
            }
        }
    }
    free_uni(last_universe);
}

// fonction that apply the simulation to a universe and print it if wanted :  it considers the cells outside of the matrix dead
void naive_simulation(Uni * p_universe, bool print_term, bool print_ppm){

    int steps = p_universe->step;

    if (print_term){
        printf("The initial universe : \n");
        aff_uni(*p_universe);
    }

    if (print_ppm){
        naive_generate_image(*p_universe, 0);
    }

    for (int i = 0; i < steps; i++){
        naive_step(p_universe);

        if (print_term){
            printf("The universe after %d steps : \n", i+1);
            aff_uni(*p_universe);
        }
        if (print_ppm){
        naive_generate_image(*p_universe, i+1);
        }
    }
}

// fonction that apply the simulation to a universe and print it if wanted :  it considers the universe as a torus
void naive_simulation_torus(Uni * p_universe, bool print_term, bool print_ppm){

    int steps = p_universe->step;

    if (print_term){
        printf("The initial universe : \n");
        aff_uni(*p_universe);
    }

    if (print_ppm){
        naive_generate_image(*p_universe, 0);
    }

    for (int i = 0; i < steps; i++){
        naive_step_torus(p_universe);
    

        if (print_term){
            printf("The universe after %d steps : \n", i+1);
            aff_uni(*p_universe);
        }
        if (print_ppm){
        naive_generate_image(*p_universe, i+1);
        }
    }
}