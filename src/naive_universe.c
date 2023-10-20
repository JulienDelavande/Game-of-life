#include <stdio.h>
#include <stdlib.h>
#include "../include/naive_universe.h"

// creation of the fonction access wich return the char of of the matrix corresponding to the ligne and column (ligne an colimn begin at 0)
char access(Uni universe, int ligne, int column){
    if( (ligne+1 > universe.height)||(column+1 > universe.width)){
        printf("dépassement ligne ou colonne");
        return 'a';
    }
    else{
        return *(universe.matrice + universe.width*ligne + column);
    }
}

// creation of a fonction that takes a pointer to a universe and set all the cells dead
void set_universe_null(Uni * p_universe){
    int height = (*p_universe).height;
    int width= (*p_universe).width;
    (*p_universe).matrice = malloc((height*width+1)*sizeof(char));
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            *((*p_universe).matrice + i*width +j) = '.';
        }
    }
    *((*p_universe).matrice +(height*width)) = '\0';
}

// creation of a fonction that displays the matrix of the universe in the terminal
void aff_uni(Uni universe){
    for (int i = 0; i < universe.height; i++){
        for (int j = 0; j < universe.width; j++){
            printf("%c", *(universe.matrice + i*universe.width +j));
        }
        printf("\n");
        
    }
}

// creation of a fonction that change the state of the cell given by the ligne and column in the universe's matrix in the reverse one
void switch_value(Uni * p_universe, int ligne, int colomn){
    int width = (*p_universe).width;
    int height = (*p_universe).height;
    if ((ligne+1 > height)||(colomn+1 > height)){
        printf("line or colomn in switch_value too high\n");
        return;
    }
    if (*((*p_universe).matrice + ligne*width + colomn) == '.'){
         *((*p_universe).matrice + ligne*width + colomn) = 'o';
    }
    else{
        *((*p_universe).matrice + ligne*width + colomn) = 'o';
    }
}

// creation of a fonction that set the cell corresponding to the given ligne and column alive in the marixe's universe
void set_alive(Uni * p_universe, int ligne, int colomn){
    int width = (*p_universe).width;
    int height = (*p_universe).height;
    if ((ligne+1 > height)||(colomn+1 > height)){
        printf("ligne or colomn in change_value_uni too high\n");
        return;
    }
    *((*p_universe).matrice + ligne*width + colomn) = 'o';
}

// creation of a fonction that set the cell corresponding to the given ligne and column dead in the marixe's universe
void set_dead(Uni * p_universe, int ligne, int colomn){
    int width = (*p_universe).width;
    int height = (*p_universe).height;
    if ((ligne+1 > height)||(colomn+1 > height)){
        printf("ligne or colomn in change_value_uni too high\n");
        return;
    }
    *((*p_universe).matrice + ligne*width + colomn) = '.';
}

// fonction that return a copy a given universe
Uni copy_uni(Uni universe){
    Uni new_universe = {universe.height, universe.width, universe.step};
    new_universe.matrice = malloc((universe.height*universe.width+1)*sizeof(char));
    int i = 0;
    while (i<universe.height*universe.width+1){
        *(new_universe.matrice + i) = *(universe.matrice + i);
        i++;
    }
    return new_universe;
}

// fonction that clear the matrix of a given universe
void free_uni(Uni universe){
    free(universe.matrice);
}

