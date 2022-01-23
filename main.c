/**
 * @file main.c
 * @author Ayush Regmi (ayushregmi736@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <conio.h>
#include "ASCII_ARTS.c"
#include "PrintBoard.c"
#include "SolvingFunctions.c"

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
 * 
 * @brief The Main Function   
 * @brief Main Entery of the Program 
 * 
 * @return int 
 */
int main()
{   
    //static char name[20];
    static char name[20];
    char start, algorithm;
    char choice;
    int row = 0;
    int col = 0;

    /**
     * @brief The Sudoku Board!!
     * 
     * The user/programmer is supposed to enter the valid Sudoku problem in this Board
     * The Dimension of the board is 9x9:
     * 9 rows and 9 columns
     * 9 Sub-grids with 3 rows and 3 columns each
     * 
     */
    int board[N][N] = { {3, 0, 6,  5, 0, 8,  4, 0, 0},   
                        {5, 2, 0,  0, 0, 0,  0, 0, 0}, 
                        {0, 8, 7,  0, 0, 0,  0, 3, 1},

                        {0, 0, 3,  0, 1, 0,  0, 8, 0}, 
                        {9, 0, 0,  8, 6, 3,  0, 0, 5}, 
                        {0, 5, 0,  0, 9, 0,  6, 0, 0}, 

                        {1, 3, 0,  0, 0, 0,  2, 5, 0},
                        {0, 0, 0,  0, 0, 0,  0, 7, 4}, 
                        {0, 0, 5,  2, 0, 6,  3, 0, 0} };


    // UPDATED from line 68 to 80
    printf("\n\n");
    printf("Hey Y'all !!");
	printf("\n<press ENTER key>"); getchar();
	printf("\nOhhh Wait!!!,  You should enter to Fullscreen to really enjoy this program (^_^)"); getch();
	printf("\nOkay pal, That seems awesome!!");getch();
	printf("\nBy the way,\n");getch();
	printf("\nI forgot to ask  your name (^_^)\nWhat is your name Pal?(I should have asked you in the first place XD)\nName:");
    scanf("%s", name);
	
	printf("\nHello %s (^_^)",name);getch();
	printf("\n-------------------Welcome %s to The AYUSH SUDOKU SOLVER  -\\_(``/)_/- ------------------------", name); getch();
	printf("\nPress <ENTER> to Begin"); getch();
	
    
    printf("\n\n");

    /*  This function if from ASCII_ARTS Header file 
        which Displays the title of this project in the 
        ASCII Art format*/
    DisplayTitle();
    printf("\n\n");

    //UPDATED from line 93 to 107

    printf("Hey %s Do you know the rules of SUDOKU ?", name); getch();
    printf("\nIf you don't, first see the Rules, Okay %s?? \n", name); getch();
    printf("\nIf you wanna See the rules press 'Y': \nIf you don't, then press 'N' to solve directly: ");
    scanf("%*c%c", &choice);

    switch (choice)
    {
    case 'y':
        rules();
        break;
    
    case 'n':
        printf("\n\nHummmm....You seem super intelligent %s !! :)\n", name);
        break;
    }

    getch();
    printf("\n\nIf the Grid has Valid Data\n\nPress Any Key to Solve the Sudoku:\n");
    scanf("%c", &start);
    getch();

    /**
     * @brief When a Key is pressed, The Algorithm starts to execute.
     * 
     */
    START(board, row, col);
    
    printf("\n\nWow %s !!! We did it!!\n", name); getch();
    printf("Don't You wanna know how did that work %s??\n", name); 
    printf("\nIf you wanna know the Algorithm, Press 'A': ");
    scanf("%c",&algorithm);
    
    switch (algorithm)
    {
    case 'a':
        algo();
        break;
    
    default:
        break;
    }
    
    printf("\n\nTHANK YOU %s (^_^)\nEnter Any Key to Terminate !!!\n", name);
    
    getch();

    return 0;
}
