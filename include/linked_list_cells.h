/**
 * @file linked_list_cell.h
 *
 * @brief Simple definition of the structure Linked_list_cell with fonctions
 *
 * @author Julien Delavande
 *
 * This is a definition of the structure Linked_list_cell which represent a Linked list containing cells.
 * Each cell contains the coordonates of the universe cell c=column=abscissa, l=line=ordonate and a booelan that is true if the cell is alive
 *
 * The API of the linked_list_cell.h is defined as follows:
 *
 * - a function to create an empty list
 * - a fonction to add a cell at the beguining of the list
 * - a fonction to access the size of the list
 * - a fonction to access an cell of the list by giving the posistion of the cell in the list
 * - a fonction to see if a list is empty
 * - a fonction to insert a cell in a given position in a list
 * - a fonction to remove a cell of the list
 * - a fonction to remove the dead cells from the list
 * - a fonction to remove a list (desalocate the memory correctly)
 * - a fonction to print the list in the terminal
 * - a fonction to compare the position of the cell : true if the first is before the second
 * - a fonction to sort a list using the merge sort algorithm
 * - a fonction to cut a list in two list (in the midle)
 * - a fonction to say if a cell is in the list
 * 
 */

#ifndef LINKED_LIST_CELL_H
#define LINKED_LIST_CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief An alias to the cell structure
 */
typedef struct Cell Cell;

/**
 * @brief An alias to the Linked_list structure (pointer to a cell)
 */
typedef Cell * Linked_list_cell;

/**
 * @brief the cell structure 
 */
struct Cell{
    // a boolean that is true if the universe-cell is alive
    bool alive;
    // the line of the universe-cell = ordonate
    int l;
    // the column of the universe-cell = abscissa
    int c;
    // a pointer to the next cell
    Cell * next;
};

/**
 * @brief Create an empty list
 *
 * @return an empty Linked list
 * 
 */
Linked_list_cell nil(void);


/**
 * @brief Add a cell at the beguining of the list
 *
 * @param p_list a pointer to the linked list to add the cell
 * @param alive a boolean that is true if the cell is alive
 * @param l the ligne = ordonate of the cell
 * @param c the column = abscissa of the cell
 *
 * @post After the call to `cons`, the list is modified : it contains the new cell at the beguining of it
 */
void cons(Linked_list_cell * p_list, bool alive, int l, int c);


/**
 * @brief Access the size of the list
 *
 * @param list the list to evaluate the size of
 *
 * @return the size of the list
 */
int size(Linked_list_cell list);


/**
 * @brief Access an cell of the list by giving the posistion of the cell in the list
 *
 * @param list the list to get the element from
 * @param rank the rank of the cell to extract
 *
 * @return a pointer to the cell you want to extract
 */
Cell * get_element(Linked_list_cell list, int rank);


/**
 * @brief See if a list is empty
 *
 * @param list the list to evaluate if it is empty
 *
 * @return a boolean wich is true if the linked list is empty
 */
bool is_empty(Linked_list_cell list);


/**
 * @brief Insert a cell in a given position in a list
 *
 * @param p_list a pointer to the linked list to add the cell
 * @param alive a boolean that is true if the cell is alive
 * @param l the ligne = ordonate of the cell
 * @param c the column = abscissa of the cell
 * @param pos the position you want to insert the new cell
 *
 * @post After the call to `insert`, the list is modified : it contains the new cell at the given position of the linked list
 * 
 * @pre the pos paramater should be equal or inferior to the size of the list
 */
void insert(Linked_list_cell * p_list, bool alive, int l, int c, int pos);


/**
 * @brief Remove a cell from the list
 *
 * @param p_list a pointer to the linked list to remove the cell
 * @param pos the position you want to remove the cell
 *
 * @post After the call to `remove_list`, the list is modified : the cell at the given position of the linked list has been removed
 * 
 * @pre the pos paramater should be inferior to the size of the list
 */
void remove_list(Linked_list_cell * p_list, int pos);


/**
 * @brief Remove the dead cells from the list
 *
 * @param p_list a pointer to the linked list to remove the dead cells
 *
 * @post After the call to `remove_dead`, the list is modified : the dead cells has been removed
 */
void remove_dead(Linked_list_cell * p_list);


/**
 * @brief Remove a list (desalocate the memory correctly)
 *
 * @param p_list a pointer to the linked list to delete
 *
 * @post After the call to `desalocate`, the list has been removed : all malloc has been freed and the list is now empty
 */ 
void desalocate(Linked_list_cell * p_list);


/**
 * @brief Print the list in the terminal
 *
 * @param list the linked list to print
 *
 * @post After the call to `print_list`, the list is beeing print in the terminal
 */ 
void print_list(Linked_list_cell list);


/**
 * @brief Compare the position between the two cells : true if the first is before the second
 *
 * @param cell_1 the first cell to compare
 * @param cell_2 the second cell to compare
 *
 * @return a boolean wich is true the cell 1 is before the cell 2
 */
bool compare_cell(Cell cell_1, Cell cell_2);


/**
 * @brief Sort a list using the merge sort algorithm
 *
 * @param list the list to sort
 *
 * @return the list which has been sorted
 */
Linked_list_cell fusion_sort(Linked_list_cell list);


/**
 * @brief Cut a list in two list (in the midle)
 *
 * @param list the list to cut in two
 *
 * @return a pointer toward the two expected list (firt part of the given list and the Pointer + 1 the second part of the given list)
 */
Linked_list_cell * cut_list_two(Linked_list_cell list);


/**
 * @brief Say if a cell is in the list
 *
 * @param list the list to search into
 * @param l the line of the cell to say if it is in the list
 * @param c the column of the cell to say if it is in the list
 *
 * @return boolean that is true if the cell is in the list
 */
bool is_in_list(Linked_list_cell list, int l, int c);


#endif