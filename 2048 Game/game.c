//noahlr2, gsayy2
#include "game.h"
/**
My program does necessary calculations to have the game 2048 run. First two methods, make_game and remake_game
create a game board with dimensions entered by user. It also sets the board to a default state and score to 0. 
remake_game just remakes the current board. get_cell gets a pointer to a cell on the board. move_w/a/s/d moves
the board and the tiles to the left, right, up, or down depending on which tile you clilck. They also merge similar tiles 
and modify the score. check_board checks if the board is the same or not after a move.




*/

game * make_game(int rows, int cols)
/*! Create an instance of a game structure with the given number of rows
    and columns, initializing elements to -1 and return a pointer
    to it. (See game.h for the specification for the game data structure) 
    The needed memory should be dynamically allocated with the malloc family
    of functions.
*/
{
    //Dynamically allocate memory for game and cells (DO NOT modify this)
    game * mygame = malloc(sizeof(game));
    mygame->cells = malloc(rows*cols*sizeof(cell));

    //YOUR CODE STARTS HERE:  Initialize all other variables in game struct
    (*mygame).rows = rows; //initaalizes rows
    (*mygame).cols = cols; //initialilzes cols
    (*mygame).score = 0;// sets score to 0
    for (int i = 0; i < rows*cols; i++){
        (*mygame).cells[i] = -1; //sets every cell to empty
    }


    return mygame;
}

void remake_game(game ** _cur_game_ptr,int new_rows,int new_cols)
/*! Given a game structure that is passed by reference, change the
	game structure to have the given number of rows and columns. Initialize
	the score and all elements in the cells to -1. Make sure that any 
	memory previously allocated is not lost in this function.	
*/
{
	/*Frees dynamically allocated memory used by cells in previous game,
	 then dynamically allocates memory for cells in new game.  DO NOT MODIFY.*/
	free((*_cur_game_ptr)->cells);
	(*_cur_game_ptr)->cells = malloc(new_rows*new_cols*sizeof(cell));

	 //YOUR CODE STARTS HERE:  Re-initialize all other variables in game struct
     (*_cur_game_ptr)->rows = new_rows; //sets new game rows
    (*_cur_game_ptr)->cols = new_cols; //sets new game cols
    (*_cur_game_ptr)->score = 0; //resets score
    for (int i = 0; i < new_rows*new_cols; i++){
        (*_cur_game_ptr)->cells[i] = -1; //initializing all tiles to 0
    }



	return;	
}

void destroy_game(game * cur_game)
/*! Deallocate any memory acquired with malloc associated with the given game instance.
    This includes any substructures the game data structure contains. Do not modify this function.*/
{
    free(cur_game->cells);
    free(cur_game);
    cur_game = NULL;
    return;
}

cell * get_cell(game * cur_game, int row, int col)
/*! Given a game, a row, and a column, return a pointer to the corresponding
    cell on the game. (See game.h for game data structure specification)
    This function should be handy for accessing game cells. Return NULL
	if the row and col coordinates do not exist.
*/
{
    //YOUR CODE STARTS HERE
   
    int maxRow = (*cur_game).rows;
    int maxCol = (*cur_game).cols; //sets rows and cols
    int pos = (row*maxCol+col) ; //finds position
    if(row > maxRow || col > maxCol){ //
        return NULL; //return nothing if row or col isnt valid
    }
     
    return &(*cur_game).cells[pos]; //this returns current game cell pointer
}

int move_w(game * cur_game)
/*!Slides all of the tiles in cur_game upwards. If a tile matches with the 
   one above it, the tiles are merged by adding their values together. When
   tiles merge, increase the score by the value of the new tile. A tile can 
   not merge twice in one turn. If sliding the tiles up does not cause any 
   cell to change value, w is an invalid move and return 0. Otherwise, return 1. 
*/
{/**
    For each of the N columns in the MxN matrix:
        For each of the M elements within this column
            If the current row value is not empty
                Find the first available target row (the smallest row value (in the current column) that is empty and is less than current row number)
                Assuming target row is less than current row number
                    Copy current row value into target row
                    Clear current row contents



*/
    //YOUR CODE STARTS HERE
int col = (*cur_game).cols;  //sets rows
int row = (*cur_game).rows;//sets cols
int index; //index of pos
int cellVal; //val of pos
int indexOne; //index of tile comparing
int cellValOne; //val of tile comparing
int change = 0; //returns if board changes or  nah
for(int i = 0; i < col; i++){ //loop through each column individually 
    
              
        for (int k = 0; k < row; k++){ //loop through the swapping code enough times to swap every value enough times
    for(int j = 0; j < row-1; j++){//loop through a column one time for every row -1
      
        index = (j*col)+i; //set index 
        cellVal = (*cur_game).cells[index]; //find value at index
        indexOne = index + col; //index of the next tile in column
        cellValOne = (*cur_game).cells[indexOne]; //value of next tile in column 
   
        if((cellVal == -1) && (cellValOne != -1)){ //if a cell is 0 and the next cell isnt, 
            (*cur_game).cells[index] = cellValOne; //swap indexed cell up one
            (*cur_game).cells[indexOne] = -1; 
            change = 1;      //set value indicating change to 1.
        }
    }
   
    }
    for(int j = 0; j < row-1; j++){ 
        index = (j*col)+i; //same index as above, next 3 lines same as above
        cellVal = (*cur_game).cells[index];
        indexOne = index + col;
        cellValOne = (*cur_game).cells[indexOne];   
        if((cellVal == cellValOne)&& (cellValOne != -1)){ //if cell is same val as its next index and both arent 0, 
            (*cur_game).cells[index] = cellVal * 2; //"Merge them" by multiplying one by two and deleting other cell
            (*cur_game).cells[indexOne] = -1; 
            change = 1; //change happened
            (*cur_game).score += cellVal *2; //add the merged cell value to total score.
        }
    }
      for (int k = 0; k < row; k++){     //this is the same code chunk as above, same comments apply.
     for(int j = 0; j < row-1; j++){ //this needs to be run twice to move everything after merging eligable tiles.
      
        index = (j*col)+i; 
        cellVal = (*cur_game).cells[index];
        indexOne = index + col;
        cellValOne = (*cur_game).cells[indexOne]; 
   
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1; 
            change = 1;      
        }
    }   
        
     }
        
    
        
}

    return change; //rreturn if value changed or not 
};

int move_s(game * cur_game) //slide down
{
    //YOUR CODE STARTS HERE

    /**
    This code is the same as move_w, with preparations to merge down. Same comments apply.
    */
int col = (*cur_game).cols; 
int row = (*cur_game).rows;
int index;
int cellVal;
int indexOne;
int cellValOne;
int change = 0; //initializes all variables
for(int i = 0; i < col; i++){ //go through each column 
    
              
       for (int k = 0; k < row; k++){   //loop through column checking row^2 times
    for(int j = row-1; j > 0; j--){//loop through row comparing two vals
        index = (j*col)+i;
        cellVal = (*cur_game).cells[index];
        indexOne = index - col;
        cellValOne = (*cur_game).cells[indexOne]; //get vals of two comparison values
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;  //cell replacing, look at move_w for more examples
            change = 1;      
        }
    }
       }
    for(int j = row-1; j > 0; j--){ 
        index = (j*col)+i; 
        cellVal = (*cur_game).cells[index];
        indexOne = index - col; //initializing loops same as before 
        cellValOne = (*cur_game).cells[indexOne];   
        if((cellVal == cellValOne)&& (cellVal != -1)){ //checks to see if cell is same value 
            (*cur_game).cells[index] = cellVal * 2;
            (*cur_game).cells[indexOne] = -1;
            change = 1; 
            (*cur_game).score += cellVal *2; //add score if merge was made 
        }
    } 
        for (int k = 0; k < row; k++){ //same as above loop
     for(int j = row - 1; j > 0; j--){
        index = (j*col)+i;
        cellVal = (*cur_game).cells[index];
        indexOne = index - col;
        cellValOne = (*cur_game).cells[indexOne]; 
        if((cellVal == -1) && (cellValOne != 1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;    
            change = 1;  
        }
    }   
        } //see move_w for more details
        
       
        
    
        
}    
    return change;
};

int move_a(game * cur_game) //slide left
{
    //YOUR CODE STARTS HERE
    /**
    This code is the same as move_w, with preparations to merge left. Same comments apply.
    */
int col = (*cur_game).cols; 
int row = (*cur_game).rows;
int index;
int cellVal;
int indexOne;
int cellValOne;//initializes all variables 
int change = 0;
for(int i = 0; i < row; i++){//loop trhough all rows
    
              
     for (int k = 0; k < col; k++){   
    for(int j = 0; j < col-1; j++){ //compare column values
        index = (i*col)+j; 
        cellVal = (*cur_game).cells[index];
        indexOne = index + 1;
        cellValOne = (*cur_game).cells[indexOne]; //sets up variabls and indexes
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;  
            change = 1;    //moves the cells to 0s 
        }
    }
     }
    for(int j = 0; j < col-1; j++){ //this combines adjescent cells 
        index = (i*col)+j;
        cellVal = (*cur_game).cells[index];
        indexOne = index + 1;
        cellValOne = (*cur_game).cells[indexOne];   
        if((cellVal == cellValOne) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellVal * 2;
            (*cur_game).cells[indexOne] = -1;
            (*cur_game).score += cellVal *2;
            change = 1;
            
        }
    }
        for (int k = 0; k < row; k++){ //moves cells to left side of board
     for(int j = 0; j < col-1; j++){
        index = (i*col)+j;
        cellVal = (*cur_game).cells[index];
        indexOne = index + 1;
        cellValOne = (*cur_game).cells[indexOne]; 
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;   
            change = 1;   
        }
    }   
        
        }
        
    
        
}  
    
    return change;
};
/**
    This code is the same as move_w, with preparations to merge right. Same comments apply.
    */
int move_d(game * cur_game){ //slide to the right
    //YOUR CODE STARTS HERE

  int col = (*cur_game).cols; 
int row = (*cur_game).rows;
int index;
int cellVal;
int indexOne;
int cellValOne;
int change = 0;
for(int i = 0; i < row; i++){
    
              
       for (int k = 0; k < col; k++){ //moves cells to right
    for(int j = col-1; j > 0; j--){
        index = (i*col)+j;
        cellVal = (*cur_game).cells[index];
        indexOne = index - 1;
        cellValOne = (*cur_game).cells[indexOne]; 
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;  
            change = 1;    
        }
    }
       }
    for(int j = col-1; j > 0; j--){ //combines cells to the right 
        index = (i*col)+j;
        cellVal = (*cur_game).cells[index];
        indexOne = index - 1;
        cellValOne = (*cur_game).cells[indexOne];   
        if((cellVal == cellValOne) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellVal * 2;
            (*cur_game).cells[indexOne] = -1;
            change = 1;
             (*cur_game).score += cellVal *2;
            
        }
    }
        for (int k = 0; k < row; k++){ //re-moves cells to right 
     for(int j = col-1; j > 0; j--){
        index = (i*col)+j;
        cellVal = (*cur_game).cells[index];
        indexOne = index - 1;
        cellValOne = (*cur_game).cells[indexOne]; 
        if((cellVal == -1) && (cellValOne != -1)){
            (*cur_game).cells[index] = cellValOne;
            (*cur_game).cells[indexOne] = -1;   
            change = 1;   
        }
    }   
        }
        
       
        
    
        
}  
    
    return change;
};

int legal_move_check(game * cur_game)
/*! Given the current game check if there are any legal moves on the board. There are
    no legal moves if sliding in any direction will not cause the game to change.
	Return 1 if there are possible legal moves, 0 if there are none.
 */
{
    //YOUR CODE STARTS HERE
    int row = (*cur_game).rows;
    int col = (*cur_game).cols; //gets rows and cols
    for(int i = 0; i < row*col; i++){
        if ((*cur_game).cells[i]== -1)//if any cell is not filled, moves can be done
        return 1;
    }
    if(move_w(cur_game)) //if you can move in any direction, theres legal moves
    return 1;
    if(move_a(cur_game))
    return 1;
    if(move_s(cur_game))
    return 1;
    if(move_d(cur_game))
    return 1;
//return 0 otherwise 
    return 0;
}


/*! code below is provided and should not be changed */

void rand_new_tile(game * cur_game)
/*! insert a new tile into a random empty cell. First call rand()%(rows*cols) to get a random value between 0 and (rows*cols)-1.
*/
{
	
	cell * cell_ptr;
    cell_ptr = 	cur_game->cells;
	
    if (cell_ptr == NULL){ 	
        printf("Bad Cell Pointer.\n");
        exit(0);
    }
	
	
	//check for an empty cell
	int emptycheck = 0;
	int i;
	
	for(i = 0; i < ((cur_game->rows)*(cur_game->cols)); i++){
		if ((*cell_ptr) == -1){
				emptycheck = 1;
				break;
		}		
        cell_ptr += 1;
	}
	if (emptycheck == 0){
		printf("Error: Trying to insert into no a board with no empty cell. The function rand_new_tile() should only be called after tiles have succesfully moved, meaning there should be at least 1 open spot.\n");
		exit(0);
	}
	
    int ind,row,col;
	int num;
    do{
		ind = rand()%((cur_game->rows)*(cur_game->cols));
		col = ind%(cur_game->cols);
		row = ind/cur_game->cols;
    } while ( *get_cell(cur_game, row, col) != -1);
        //*get_cell(cur_game, row, col) = 2;
	num = rand()%20;
	if(num <= 1){
		*get_cell(cur_game, row, col) = 4; // 1/10th chance
	}
	else{
		*get_cell(cur_game, row, col) = 2;// 9/10th chance
	}
}

int print_game(game * cur_game) 
{
    cell * cell_ptr;
    cell_ptr = 	cur_game->cells;

    int rows = cur_game->rows;
    int cols = cur_game->cols;
    int i,j;
	
	printf("\n\n\nscore:%d\n",cur_game->score); 
	
	
	printf("\u2554"); // topleft box char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // top box char
	printf("\u2557\n"); //top right char 
	
	
    for(i = 0; i < rows; i++){
		printf("\u2551"); // side box char
        for(j = 0; j < cols; j++){
            if ((*cell_ptr) == -1 ) { //print asterisks
                printf(" **  "); 
            }
            else {
                switch( *cell_ptr ){ //print colored text
                    case 2:
                        printf("\x1b[1;31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4:
                        printf("\x1b[1;32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8:
                        printf("\x1b[1;33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 16:
                        printf("\x1b[1;34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 32:
                        printf("\x1b[1;35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 64:
                        printf("\x1b[1;36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 128:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 256:
                        printf("\x1b[32m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 512:
                        printf("\x1b[33m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 1024:
                        printf("\x1b[34m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 2048:
                        printf("\x1b[35m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 4096:
                        printf("\x1b[36m%04d\x1b[0m ",(*cell_ptr));
                        break;
                    case 8192:
                        printf("\x1b[31m%04d\x1b[0m ",(*cell_ptr));
                        break;
					default:
						printf("  X  ");

                }

            }
            cell_ptr++;
        }
	printf("\u2551\n"); //print right wall and newline
    }
	
	printf("\u255A"); // print bottom left char
	for(i = 0; i < cols*5;i++)
		printf("\u2550"); // bottom char
	printf("\u255D\n"); //bottom right char
	
    return 0;
}

int process_turn(const char input_char, game* cur_game) //returns 1 if legal move is possible after input is processed
{ 
	int rows,cols;
	char buf[200];
	char garbage[2];
    int move_success = 0;
	
    switch ( input_char ) {
    case 'w':
        move_success = move_w(cur_game);
        break;
    case 'a':
        move_success = move_a(cur_game);
        break;
    case 's':
        move_success = move_s(cur_game);
        break;
    case 'd':
        move_success = move_d(cur_game);
        break;
    case 'q':
        destroy_game(cur_game);
        printf("\nQuitting..\n");
        return 0;
        break;
	case 'n':
		//get row and col input for new game
		dim_prompt: printf("NEW GAME: Enter dimensions (rows columns):");
		while (NULL == fgets(buf,200,stdin)) {
			printf("\nProgram Terminated.\n");
			return 0;
		}
		
		if (2 != sscanf(buf,"%d%d%1s",&rows,&cols,garbage) ||
		rows < 0 || cols < 0){
			printf("Invalid dimensions.\n");
			goto dim_prompt;
		} 
		
		remake_game(&cur_game,rows,cols);
		
		move_success = 1;
		
    default: //any other input
        printf("Invalid Input. Valid inputs are: w, a, s, d, q, n.\n");
    }

	
	
	
    if(move_success == 1){ //if movement happened, insert new tile and print the game.
         rand_new_tile(cur_game); 
		 print_game(cur_game);
    } 

    if( legal_move_check(cur_game) == 0){  //check if the newly spawned tile results in game over.
        printf("Game Over!\n");
        return 0;
    }
    return 1;
}
