#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------
<<<<<<< HEAD
/**
My code takes an incomplete sudoku puzzle and solves it.
I started with 3 mathods to check if a value val was present in a row, col, or 3x3 sector.
I then created another method which returned a 1 if val was not in row, col, or a 3x3 area, and 0 otheriwse.
I then created a method called solve_sodoku which solves sudoku using two helper methods. One helper methods checks
if the sudoku is done, and the other finds a spot where a value is not present yet.






*/




=======
>>>>>>> release/main

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
<<<<<<< HEAD
  for(int j = 0; j < 9; j++){ //loops through col values in row i 
    
      if(val == sudoku[i][j]){//returns 1 is val is in row
        return 1;
      }
    


  }
=======
  
>>>>>>> release/main
  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
<<<<<<< HEAD
   for(int i = 0; i < 9; i++){ //loops through row values in col i 
    
      if(val == sudoku[i][j]){//returns 1 if val is in col
        return 1;
      }
    


  }
=======
  
>>>>>>> release/main
  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);
<<<<<<< HEAD
  int rowMin = (i/3)*3;
  
  int rowMax = rowMin + 3; //these lines find top left index of a given 3x3 Square
  
  for(rowMin; rowMin <rowMax; rowMin++){//loops while top left corner is less than/eqqual  top right val
    int colMin = (j/3)*3; //THESE LINES find col top left index of a given 3x3 square
    int colMax = colMin + 3;
    for(colMin; colMin < colMax; colMin++){//loops while top left corner is less than/eqqual  bottom left val
        if(sudoku[rowMin][colMin]==val){//if val is in grid, return 1
          return 1;
        }
    }
  }


  
=======
  
  // BEG TODO
>>>>>>> release/main
  
  return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);
<<<<<<< HEAD
  if (is_val_in_row(val, i, sudoku))//if in row, return 0
  return 0;
  
  if (is_val_in_col(val, j, sudoku))//if in col, return 0
  return 0;

  if(is_val_in_3x3_zone(val, i, j, sudoku))//if in 3x3, return 0
  return 0;
//else, return 1
  return 1;
  // END TODO
}
//Function: check_filled
//Return True if sudoku is filled

int check_filled(int sudoku[9][9]){
  int k, l;
  for(k = 0; k < 9; k++){//loops through every val with nested for loop
    for(l = 0; l < 9; l++){
      if(sudoku[k][l]==0)//if array has empty vaal, return false fo rfilled
      return 0;
    }
  }
return 1;
}

//Function: check_unused
//Return 2 digit value, first being row of unused and second being col of unused
int check_unused(int sudoku[9][9]){
int returnVal = 0; //initializing vars
int k, l;
  for(k = 0; k < 9; k++){
    for(l = 0; l < 9; l++){ //nested for loop for each valu
      if(sudoku[k][l]==0){
        returnVal = (k*10)+l; //if tile is empty, 
        return returnVal; //reurn first digit as row and second as col
      }
       
    }
  }


return returnVal;//return returnval no matter what, you know one value will be 0 if this method is called
}

=======

  // BEG TODO
  return 1;
  // END TODO
}
>>>>>>> release/main

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {
<<<<<<< HEAD
  int i, j;
  int temporary;
  if (check_filled(sudoku)) {
    return 1; //finish method of sudoku is filled
  }
  else {
    temporary = check_unused(sudoku); //find an unused tile if not filled
    i = temporary / 10; //row of unused tile
    j = temporary % 10; //col of unused tile
  }
   
  for (int num = 1; num <= 9; num++) { 
    if (is_val_valid(num, i, j, sudoku)) {  //if number works at a blank spot
      sudoku[i][j] = num; //set num into blank spot
      if (solve_sudoku(sudoku)) { //recurse, if method comes back 1 then end this method
        return 1;
      }
      sudoku[i][j] = 0; //set tile to 0 if no recursion
    }
  }
  return 0; 
=======

  // BEG TODO.

  return 0;
  // END TODO.
>>>>>>> release/main
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}





