#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/linked_list_cells.h"
#include "../include/list_universe.h"
#include "../include/list_loader.h"
#include "../include/list_ppm_writer.h"

int main(void){

    printf("=> TEST OF LIST_PPM_WRITER \n");
    Uni_l universe;
    load_list_txt(&universe, "./data/glider.txt");
    generate_ppm_list(universe, 0);
    desalocate_universe(universe);

    printf("=> LIST_PPM_WRITER OK \n");

    return 0;
}