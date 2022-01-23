/**
 * @file PrintBoard.c
 * @author Ayush Regmi (ayushregmi736@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>


/**
 * @brief The Dimension of Sudoku Board is 9x9 
 * 
 */
#define N 9



/**
 * @brief A Utility Function to Display The Sudoku Board in the Terminal
 * 
 * This function takes a 2-Dimesional array of Sudoku Grid with number of 
 * rows and number of columns,
 * and displays the Grid in the terminal.
 * 
 * A number of for loops are used to make 2-dimensional Grid and make the display visually attractive.
 * 
 * @param grid 
 * @param row 
 * @param col 
 */
void printBoard(int grid[][N], int row, int col) 
{
    for (row = 0; row < N; row++) 
    {   
        /**
         * @brief If statement to print the Boarder after every 3 rows in the Grid.
         * 
         */
        if (row % 3 == 0 && row != 0) 
        {
            printf("==========++===========++==========\n");
        } 
        
        for (col = 0; col < N; col++) 
        {   
            /**
             * @brief If statement to print the Boarder after every 3 columns in the Grid.
             * 
             */
            if (col % 3 == 0 && col != 0) 
            {
                printf("|| ");
            } 

            printf("%d ", grid[row][col]);

            /**
             * @brief If statement to print the dotted boundary between every columns in the Grid.
             * 
             */
            if (col != 8 && col != 2 && col != 5) 
            {
                printf(": ");
            }
        } 
        printf("\n");
    }
}

// Updated from line 77 to 94

void rules()
{   
    printf("\n\n---------RULES----------");
    printf("\n\n1. Every square has to contain a single number.\n");
    printf("2. Only the numbers from 1 to 9 can be used\n");
    printf("3. Each 3x3 box can only contain each number from 1 to 9 once\n");
    printf("4. Each vertical column can only contain each number from 1 to 9 once\n");
    printf("5. Each horizontal row can only contain each number from 1 to 9 once\n");
}

void algo()
{   
    printf("\n\n-----------THE ALGORITHM------------");
    printf("\n\n1. We Assigned the numbers one by one to empty cells.\n");
    printf("2. Before assigning, we checked if it's safe or not.\n");
    printf("3. After checking for safety, we assigned the number,\n");
    printf("   and recursively checked whether that assignment leads to a solution or not.\n");
}