<<<<<<< HEAD
/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){
}

				
				
			

=======
/*noahlr2
 INTRO PARAGRAPH
This code has three methods to help update the game of life board.
countliveneighbor: 
This method counts the neighbors of a given tile. This is done by first seeing
if the tile is in a corner, border, or middle. Depending on its position, this method
counts if there are any other live tiles bordering diagonally or next to the tile inputted. 
This method doesnt count any tiles that are outside of the board parameters.

UpdateBoard
all update board does is update the current state depending on the rules of the game of life.
If a tile has exactly three neighbors, it is alive irrespective of its previous condition.
If a tile is currently alive and hasa two neighbors, it stays alive. Otherwise a tile is dead

aliveStable
this is a copyy of update board, but if the board doesnt change at all the program ends.

*/






/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){
int alive = 0; //alive neighbor counter
int left, right, top, bottom;
left = right = bottom = top = 0; //variables to see if a tile wont haave 8 neighbors
int cornercheck = 0; //adder to see how many walls a tile is touching
int i;
int pos = (boardColSize*row)+col; //this sets pos equal to the position of the tile in a 1D array

if(row == 0) //next 4 if statements checks if the tile is on a border
top = 1;

if(col == 0)
left = 1;

if((boardRowSize - row) == 1)
bottom = 1;

if((boardColSize - col) == 1)
right = 1;

cornercheck = top + bottom + left + right; //adds how many borders a tile is touching
if(cornercheck==2){ //if tile is in corner
   if(top){//if tile is in a top corner
    if(top == left){ 
        alive = board[pos+1] + board[pos+boardColSize] + board[pos+boardColSize+1]; //adds all 3 tiles bordering top left
    }
    if(top == right){
        alive = board[pos-1] + board[pos + boardColSize] + board[pos + boardColSize -1]; //adds all 3 tiles bordering top right
    }
   }
   if(bottom){//if tile is in bottom corner
    if(bottom == left){
        alive = board[pos+1] + board[pos-boardColSize] + board[pos - boardColSize + 1]; //adds 3 tiles bordering bottom left
    }
    if(bottom == right){
       alive = board[pos-1] + board[pos - boardColSize] + board[pos - boardColSize -1]; //adds 3 tiles bordering bottom right
    }
   }
}
if(cornercheck == 1){//if on a wall
if(top){ //adds all bordering tiles if on top wall
    for (i = -1; i < 2; i++ ){
        alive = alive + board[pos + i + boardColSize]; 
        
    }
alive = alive + board[pos - 1] + board[pos + 1];
}
if(bottom){//adds all bordering tiles if on bottom wall
     for (i = -1; i < 2; i++ ){
        alive = alive + board[pos + i - boardColSize];
        
    }
alive = alive + board[pos - 1] + board[pos + 1];
}
if(left){ //adds all bordering tiles if on left wall
     for (i = -1; i < 2; i++ ){
        alive = alive + board[pos + 1 + (i * boardColSize)];
        
    }
alive = alive + board[pos - boardColSize] + board[pos + boardColSize];
}
if(right){ //adds all bordering tiles if on right wall
     for (i = -1; i < 2; i++ ){
        alive = alive + board[pos - 1 + (i*boardColSize)];
       
    }
 alive = alive + board[pos - boardColSize] + board[pos + boardColSize];
}




}
if(cornercheck == 0){ //if in middle of board
for(i = -1; i < 2; i++){
    alive = alive + board[pos-boardColSize + i]; //these 3 lines adds all bordering tiles
    alive = alive + board[pos+boardColSize + i];
    alive = alive + board[pos + i];
}
alive = alive - board[pos];//removes center tile
}



return alive; //returns alive
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {
int length = boardColSize * boardRowSize; //length of array
int tempArr[length]; //temp array of length of original one
for(int i = 0; i < length; i++){//for every val in the array:
int liveNeigh = countLiveNeighbor(board, boardRowSize, boardColSize, i/boardColSize,i%boardColSize); //check neighbors for every tile
if (liveNeigh == 3) //if a tile has 3 neighbors, make it alive
tempArr[i] = 1;
else if((liveNeigh == 2)&&(board[i]==1)) //if aa tile has 2 neighbors and is alive, keep alive
tempArr[i] = 1;
else
tempArr[i]=0; //any other tile turn dead
}
for(int j = 0; j < length; j++) //set temp array and update to board
board[j] = tempArr[j];
}




/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){
//starting here, same comments as above method
int length = boardColSize * boardRowSize;
int tempArr[length]; 
for(int i = 0; i < length; i++){
int liveNeigh = countLiveNeighbor(board, boardRowSize, boardColSize, i/boardColSize,i%boardColSize);
if (liveNeigh == 3)
tempArr[i] = 1;
else if((liveNeigh == 2)&&(board[i]==1))
tempArr[i] = 1;
else
tempArr[i]=0;
}
//same comments ends here
int diff = 0; //counter to see how diff the next state is

for(int l = 0; l < length; l++){ //for every array vaal
if(board[l] != tempArr[l]) //if board is diff, add 1 to diff
diff++;
}
if((diff==0)) //if board is diff, return 0. else return 1.
return 1;

return 0;


}

>>>>>>> refs/remotes/origin/main
