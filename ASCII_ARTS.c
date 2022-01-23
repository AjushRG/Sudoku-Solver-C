/**
 * @file ASCII_ARTS.c
 * @author Ayush Regmi(you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>

/**
 * @brief The DisplayTitle function displays the ASCII Art image from the file image.txt
 * 
 * 
 * 
 * @return int 
 */
int DisplayTitle() 
{ 
    /**
     * @brief Text files are the normal .txt files. 
     * You can easily create text files using any simple text editors such as Notepad.

     *When you open those files, you'll see all the contents within the file as plain text.
      You can easily edit or delete the contents.

     *They take minimum effort to maintain, are easily readable, and 
     provide the least security and takes bigger storage space.
     * 
     */
    char *filename = "image.txt";
    FILE *fptr = NULL;

    /**
     * @brief “r” – Searches the file image.txt. 
     * 
     * If the file is opened successfully fopen( ) loads it into memory and 
     * sets up a pointer which points to the first character in it. 
     * 
     * If the file cannot be opened fopen( ) returns NULL.
     * 
     */
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

     int MAX_LEN = 128;
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
      printf("%s",read_string);


    fclose(fptr);
    return 0;
}


/**
 * @brief The BeforeSolving function displays the ASCII Art image from the file BeforeSolving.txt
 * 
 * @return int 
 */
int BeforeSolving() 
{
    char *filename = "BeforeSolving.txt";
    FILE *fptr = NULL;
    
    /**
     * @brief “r” – Searches the file BeforeSolving.txt. 
     * 
     * If the file is opened successfully fopen( ) loads it into memory and 
     * sets up a pointer which points to the first character in it. 
     * 
     * If the file cannot be opened fopen( ) returns NULL.
     * 
     */
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

     int MAX_LEN = 128;
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
      printf("%s",read_string);


    fclose(fptr);
    return 0;
}


/**
 * @brief The AfterSolving function displays the ASCII Art image from the file AfterSolving.txt
 * 
 * @return int 
 */
int AfterSolving() 
{
    char *filename = "AfterSolving.txt";
    FILE *fptr = NULL;

    /**
     * @brief “r” – Searches the file AfterSolving.txt. 
     * 
     * If the file is opened successfully fopen( ) loads it into memory and 
     * sets up a pointer which points to the first character in it. 
     * 
     * If the file cannot be opened fopen( ) returns NULL.
     * 
     */
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

     int MAX_LEN = 128;
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
      printf("%s",read_string);


    fclose(fptr);
    return 0;
}


/**
 * @brief The Error function displays the ASCII Art image from the file Error.txt
 * 
 * @return int 
 */
int Error() 
{
    char *filename = "Error.txt"; // Updated 
    FILE *fptr = NULL;

    /**
     * @brief “r” – Searches the file Error.txt. 
     * 
     * If the file is opened successfully fopen( ) loads it into memory and 
     * sets up a pointer which points to the first character in it. 
     * 
     * If the file cannot be opened fopen( ) returns NULL.
     * 
     */
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

     int MAX_LEN = 128;
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
      printf("%s",read_string);


    fclose(fptr);
    return 0;
}

