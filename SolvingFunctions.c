/**
 * @file SolvingFunctions.c
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
 * @brief The Blank Space in Sudoku Board is denoted by '0'
 * 
 */
#define BLANK 0


/**
 * @brief The START function is a Utility Function which displays the whole Solution of this problem.
 * 
 * When the user presses 'S' button then the START function displays the Unsolved Grid to the Users
 * 
 * After that it displays the Solution of that Sudoku Grid.
 * 
 * @param grid
 * @param row 
 * @param col 
 */
void START(int (*) [N], int row, int col);



/**
 * @brief The SolveBoard function assign valid values to all Blank locations provided by find_empty function
 * 
 * This SolveBoard function is the Heart of the entire solution.
 * 
 * This is the function wich triggers backtracking.
 * 
 * This functions takes a partially filled-in grid and attempts to assign values to all Blank locations in such a way to meet the requirements for Sudoku Solution (non-duplication across rows, columns, and boxes)
 * 
 * This function first check if there is no unassigned location, with the help of find_empty function and:
 * IF there is no Blank location in the entire grid then, 
 * We are done! We Solved the problem
 * 
 * @param grid
 * @param row 
 * @param col 
 * @return int
 */
int SolveBoard(int (*) [N], int row, int col);




/**
 * @brief The find_empty function finds and check whether the given entry or (Location) in the grid is Blank or not
 * 
 * The find_empty function searches the grid to find an entry that is still unassigned. 
 * 
 * If found, the reference parameters row, col will be set the location that is unassigned, and 1 is returned i.e. True.
 * 
 * If no assigned entried remain, 0 is returned i.e. False.
 * 
 * @param grid
 * @param row 
 * @param col 
 * @return int 
 */
int find_empty(int (*) [N], int *row, int *col);




/**
 * @brief The isSafeNum function checks the probability of the assigned num to be legal to the given row, column and 3x3 Box.
 * 
 * This function returns either 1 or 0 indicating : either True or False, which indicates whether it will be legal to assign num to the given row, col location.
 * 
 * Check if 'num' is not already placed in current row, current cloumn and current 3x3 box.
 * 
 * @param grid
 * @param row 
 * @param col 
 * @param num
 * @return int
 */
int isSafeNum(int (*) [N], int row, int col, int num);




/**
 * @brief isValidColumn function checks the validity of an assigned entry in the specified column
 * 
 * If the assigned entry in the specified column matches the given number then the function returns a true value i.e '1'.
 * 
 * And if the assigned entry in that specified column does not match the given number then the function returns a false value i.e. '0' 
 * 
 * @param grid
 * @param row 
 * @param col 
 * @return int
 */
int isValidColumn(int (*) [N], int col, int num);




/**
 * @brief isValidRow function checks the validity of an assigned entry in the specified row
 * 
 * If the assigned entry in the specified row matches the given number then the function returns a true value i.e '1'.
 * 
 * And if the assigned entry in that specified row does not match the given number then the function returns a false value i.e. '0' 
 * 
 * @param grid
 * @param row 
 * @param num 
 * @return int 
 */
int isValidRow(int (*) [N], int row, int num);




/**
 * @brief isValidBlock function checks the validity of an assigned entry in the specified 3x3 sub-grid (Box)
 * 
 * If the assigned entry in the specified 3x3 Sub-Grid matches the given number then the function returns a true value i.e '1'.
 * 
 * And if the assigned entry in that specified 3x3 Sub-Grid does not match the given number then the function returns a false value i.e. '0'
 * 
 * @param grid
 * @param boxStartRow 
 * @param boxStartCol 
 * @param num 
 * @return int 
 */
int isValidBlock(int (*) [N], int boxStartRow, int boxStartCol, int num);




// Codes of All Fucnions 


/* The START function displays the whole Solution of this problem */
void START(int board[][N], int row, int col)
{   
    /* This function is also from the ASCII_ARTS Header file 
    wich displays the word 'Before Solving' in the ASCII Art format */
    BeforeSolving();
    printf("\n\n");

    /* This fucntion is from the PrintBoard Header file 
    which prints the Sudoku Grid provided by the user in unsolved format */
    printBoard(board, row, col);


    if (SolveBoard(board, row, col))
    {   
        printf("\n\n");

        /* This function is also from the ASCII_ARTS Header file 
        wich displays the word 'After Solving' in the ASCII Art format */
        AfterSolving();
        printf("\n\n");

        /* This fucntion is from the PrintBoard Header file 
        which prints the Solution of the Sudoku Grid provided by the user*/
        printBoard(board, row, col);
    }

    else
    {
        printf("\n\n");

        /* This function if from ASCII_ARTS Header file 
        which Displays the error message  in the ASCII Art format 
        if the provided sudoku board is invalid*/
        Error();
        printf("\n\n");
    }
}



/* The SolveBoard function assign valid values to all Blank locations provided by find_empty function
 * 
 * This SolveBoard function is the Heart of the entire solution.
 * 
 * This is the function wich triggers backtracking. */
int SolveBoard(int grid[][N], int row, int col) {
    
    // check if there are no Blank location,
    // If true, We are done!!!
    if (!find_empty(grid, &row, &col))
    {
        return 1; // success!f
    }
    
    // consider num => 1, 2, 3, 4, 5, 6, 7, 8, 9
    for (int num = N; num >= 1; num--)
    {   
        // The isSafeNum function checks the probability of
        // the assigned num to be legal to the given row, column and 3x3 Box.
        if (isSafeNum(grid, row, col, num))
         {  
            grid[row][col] = num;

            // Return, if success !!
            if (SolveBoard(grid, row, col))
            {
                return 1; // Success!!
            }

            //Failure, unmake & try again i.e. BackTrack!!!
            // This return triggers the backtracking
            grid[row][col] = BLANK;
         }
         
    }

    return 0;
}



// The find_empty function finds and check whether 
//the given entry or (Location) in the grid is Blank or not.
int find_empty(int grid[][N], int *row, int *col) 
{
    for (*row = 0; *row < N; (*row)++) 
    {
        for (*col = 0; *col < N; (*col)++) 
        {
            if (grid[*row][*col] == BLANK) 
            {
                return 1;
            }   
        }   
    } 
    return 0;
}



// The isSafeNum function checks the probability of 
//the assigned num to be legal to the given row, column and 3x3 Box.
int isSafeNum(int grid[][N], int row, int col, int num) 
{
    return (!isValidRow(grid, row, num) &&
            !isValidColumn(grid, col, num) &&
            !isValidBlock(grid, row - (row % 3), col - (col % 3), num));
}



// isValidColumn function checks the validity of an assigned entry in the specified column
int isValidColumn(int grid[][N], int col, int num) 
{
    
    for (int row = 0; row < N; row++) 
    {
        if (grid[row][col] == num) 
        {
            return 1;
        } 
    } 
    return 0;
}



// isValidRow function checks the validity of an assigned entry in the specified row
int isValidRow(int grid[][N], int row, int num) 
{
    for (int col = 0; col < N; col++) 
    {
        if (grid[row][col] == num) 
        {
            return 1;
        }
    } 
    return 0;
}



// isValidBlock function checks the validity of 
//an assigned entry in the specified 3x3 sub-grid (Box)
int isValidBlock(int grid[][N], int row, int col, int num)
{   
    int semiRow = 3 * (row / 3); 
    int semiCol = 3 * (col / 3);
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + semiRow][col + semiCol] == num) 
            {
                return 1;
            }
            
        }
        
    }
    return 0;
}