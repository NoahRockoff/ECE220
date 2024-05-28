/** Noah Rockoff, noahlr2
      .-.
     (o.o)
      |=|
     __|__
   //.=|=.\\
  // .=|=. \\
  \\ .=|=. //
   \\(_=_)//            SkElE bOnEs wOoooOOOooooOOOoo
    (:| |:)             hi TAs <3
     || ||              i am losing it
     () ()
     || ||
     || ||
    ==' '==

This prograam takes a file for a maze, parses it, puts it into a 2D array, and then solves it using a
DFS (depth first search) algorithm. the first method, createMax, takes a file and creates a maze with it.
it takes the dimensions in the first line, and then parses the file and creates and array with the given map.
destroyMaze destroys the maze, it frees up memory. printMaze prints the maze. simple. the DFS method searches through 
the maze finding aa solution using the algorithm.



*/


#include <stdio.h>
#include <stdlib.h>
#include "maze.h"


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None 
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName)
{
    // Your code here. Make sure to replace following line with your own code.
   FILE* txt = fopen(fileName, "r"); //create file
    maze_t* maze = (maze_t*) malloc(sizeof(maze_t)); //create maze
     int col;
     fscanf(txt, "%d", &col); //find col and create it
    maze->width = col;
    int row ;
    fscanf(txt, "%d", &row); //find row and create it
    maze->height = row;
    
  
   maze->cells = (char**)malloc(row*sizeof(int*)); //copied from lecture slides, this allocates memory for a 2d array
   for (int i = 0; i< row; i++){
        maze->cells[i] = (char*)malloc(col*sizeof(int)); //thisa allocates memory for the cells
   
   }
   char charInput = fgetc(txt); //get first maze value
    int rowCount = 0;
    int colCount = 0;//set rows and cols to 0
    while(charInput != EOF){ //find chars until end of file
       // printf("%c %d %d\n", charInput, row, col);
            
            if(charInput == 'S'){ //if char is an S, set the starting pos and aarray char
                maze->startRow = rowCount;
                maze->startColumn = colCount;
                maze->cells[rowCount][colCount] = charInput;
            }
            if(charInput == 'E'){ //if char is an E, set ending pos and array char
                maze->endRow = rowCount;
                maze->endColumn = colCount;
                maze->cells[rowCount][colCount] = charInput;         
            }
            if((charInput == '%') || (charInput == ' ')){ //set other tiles to array
                maze->cells[rowCount][colCount] = charInput;
            }
        
        if((charInput == '%') || (charInput == ' ') || (charInput == 'S') || (charInput == 'E')){ //if its a valid tile
            colCount++; //incriment in the array to the correct pos
            if (colCount >= col){
                colCount = 0; 
                rowCount++;
            }
        }

        charInput = fgetc(txt); //get next char
    }
        


    return maze;
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information 
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
    // Your code here.
    int row = maze->height; //sets height of maze equal to mount of rows
   
    for(int i = 0; i < row; i++){
       
            free(maze->cells[i]); //these lines free the "maze double pointers"
        
    }
    free(maze->cells); //frees the pointer to cells
    free(maze);//frees the maze
}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information 
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
    // Your code here.
    int row = maze->height;
    int col = maze->width; //get width nd height to row and col
      for(int i = 0; i < row; i++){ 
        for(int j = 0; j < col; j++){
            char cellVal = maze->cells[i][j]; //set every cell to a printable val
            printf("%c", cellVal); //print the cell

        }
        printf("\n");//new line 
    }

}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */ 
int solveMazeDFS(maze_t * maze, int col, int row)
{
    // Your code here. Make sure to replace following line with your own code.
  

    char pathData = maze->cells[row][col]; //set var to given tile

    //part 1: This error checks for out of bounds 
    if((row < 0) || (row >= maze->height))  //height = 5, max row index = 4. this means row needs to be equal or greater than height
    return 0;
    if((col < 0) || (col >= maze->width)) 
    return 0;
   

   //part 2
     if(pathData == 'E') //if its the end, return 1. this should return to base case
    return 1;
   
     //part 3   
    if(pathData != ' ' &&  pathData != 'S') //return false if the char isnt free space
    return 0;
    
    //part 4    
        if(pathData != 'S') //if you arent at the start, set cell to occupied
        maze->cells[row][col]= '*';


//weird code: order isnt supposed to matter but it does. I cant put row col+1 and col-1 next to each other
//cause it ends up going back to S. this fixes this technically

    //part 5
        if(solveMazeDFS(maze, col+1, row)) //check one col below for open space
        return 1;
   
    //part 6
         if(solveMazeDFS(maze, col, row+1)) //check one Row above
        return 1;
    
    //part 7
         if(solveMazeDFS(maze, col-1, row))//check one col above 
        return 1;
    
    //part 8
        if(solveMazeDFS(maze, col, row-1)) //check one row back
        return 1;
    
    //part 9/10    
        maze->cells[row][col]= '~';//set cell to explored and return 0.
        return 0;
}
