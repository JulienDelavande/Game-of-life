#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "../include/naive_universe.h"


int main(void){
    printf("=> TEST OF NAIVE_UNIVERSE \n");

    //creation of 5*5 universe which has 0 step by hand
    printf("---testing universe strucuture \n");
    Uni universe = {5,5,0};
    assert((universe.height == 5)&&(universe.width == 5)&&(universe.step == 0));
    printf("---universe structure OK\n");

    //set the cells dead (testing set_universe_null fonction)
    printf("---testing set_universe_null fonction \n");
    set_universe_null(&universe);
    char chaine_test[] = ".........................";
    assert(strcmp(chaine_test, universe.matrice) == 0);
    printf("---set_universe_null fonction OK\n");
    
    //first display of the universe created (testing the aff_uni fonction)
    printf("\n---testing aff_uni fonction \n");
    aff_uni(universe);
    printf("---aff_uni fonction OK\n");

    //access the universe matrix (testing the access fonction)
    printf("---testing access fonction\n");
    char a = access(universe, 2, 2);
    assert( a = '.');
    printf("     the char in place (%d,%d) : %c \n", 2, 2, a);
    char b = access(universe, 4, 4);
    assert( b = '.');
    printf("     the char in place (%d,%d) : %c \n", 5, 5, b);
    char c = access(universe, 0, 4);
    assert( c = '.');
    printf("     the char in place (%d,%d) : %c \n", 0, 4, c);
    printf("---access fonction OK \n");


    //changing the value of the universe matrix (testing set_alive and set_dead fonctions)

    printf("---testing set_alive fonction \n");
    set_alive(&universe, 2, 2);
    a = access(universe, 2, 2);
    assert( a == 'o');
    printf("the char in place (%d,%d) : %c \n", 2, 2, a);
    aff_uni(universe);
    printf("---set_alive fonction OK\n");

    printf("---testing set_dead fonction \n");
    set_dead(&universe, 2, 2);
    a = access(universe, 2, 2);
    assert( a == '.');
    printf("the char in place (%d,%d) : %c \n", 2, 2, a);
    aff_uni(universe);
    printf("---set_dead fonction OK\n");

    //testing the switch_value fonction
    printf("---testing switch_value fonction \n");
    switch_value(&universe, 0, 4);
    c = access(universe, 0, 4);
    assert( c == 'o');
    printf("the char in place (%d,%d) : %c \n", 0, 4, c);
    aff_uni(universe);
    printf("---switch_value fonction OK\n");

    //delocation of the memory
    printf("---testing free_uni fonction \n");
    free_uni(universe);
    printf("---free_uni fonction OK\n");

    printf("\n=> NAIVE_UNIVERSE OK\n");

    return 0;
}