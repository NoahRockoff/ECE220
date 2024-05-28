/*			
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */


<<<<<<< HEAD
<<<<<<< HEAD
/* THIS IS THE INTRO PARAGRAPH!!!!!!!!!!!!!!!
This program has three main methods. Method one is set_seed which takes user input to generate a random seed 
to create a random code the user should guess. Method two actually uses the seed to set every digit to a random 
nyumber from 1-8. 

the final method is make_guess which does all the logic for guessing. It does the calculations to see if your
guess has perfect matches, or the right numbers in different spots.

the entire program is the game mastermind, which is usually involving a person chosing a pattern of 4 different
colored pegs. A second player then guesses the pattern. Our program emulates that game with numbers 1-8.



*/



=======
>>>>>>> release/main
=======
>>>>>>> release/main
/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */



#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the 
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid. 
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read. 
//    We declare
<<<<<<< HEAD
<<<<<<< HEAD
   int seed;
    char post[2];  //creates the variables needed to have sscaf seperate into
//    The sscanf statement below reads the integer into seed. 
   int checking = sscanf (seed_str, "%d%1s", &seed, post); //seperates a string into components
=======
=======
>>>>>>> release/main
//    int seed;
//    char post[2];
//    The sscanf statement below reads the integer into seed. 
//    sscanf (seed_str, "%d%1s", &seed, post)
<<<<<<< HEAD
>>>>>>> release/main
=======
>>>>>>> release/main
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully. 
//    Check that the return value is 1 to ensure the user enters only an integer. 
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary. 
//    You may need to change the return statement below
<<<<<<< HEAD
<<<<<<< HEAD
 // printf("%d",checking);
   if(checking == 1){ //if theres only numbers, use the num to generate a seed.
    srand(seed);
    return 1;
    }
    else{
        printf("set_seed: invalid seed\n");
    return 0;}
=======
   
    return 0;
>>>>>>> release/main
=======
   
    return 0;
>>>>>>> release/main
}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above. 
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 8)
 *          *two -- the second solution value (between 1 and 8)
 *          *three -- the third solution value (between 1 and 8)
 *          *four -- the fourth solution value (between 1 and 8)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
    //your code here
<<<<<<< HEAD
<<<<<<< HEAD
     solution1 = *one = (rand() % 8)+1; //This sets a random number 1-8 to the memory address the middle term points to
    solution2 = *two =  (rand() % 8)+1; //the rightmost variable puts that number into a global variable
    solution3 = *three =  (rand() % 8)+1;
    solution4 = *four =  (rand() % 8)+1;
    guess_number = 1; //sets guess to one.
=======
    
>>>>>>> release/main
=======
    
>>>>>>> release/main
}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str. 
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-8). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 8)
 *          *two -- the second guess value (between 1 and 8)
 *          *three -- the third guess value (between 1 and 8)
 *          *four -- the fourth color value (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 8), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess) 
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two, 
	    int* three, int* four)
{
//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
<<<<<<< HEAD
<<<<<<< HEAD
    int w, x, y, z; //initalize a var for each guess val
    char post[2];
  int intvals = sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post); //same scanner stuff, takes a string and seprates it
=======
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
>>>>>>> release/main
=======
//  sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post)
>>>>>>> release/main
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-8. If so, it is a valid guess
//  Otherwise, it is invalid.  
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed
<<<<<<< HEAD
<<<<<<< HEAD
   if(!(((w >0) && (x >0) && (y >0) && (z >0))&& ((w <9) && (x <9) && (y <9) && (z <9))) || (intvals != 4 )){
    printf("make_guess: invalid guess\n"); //this horrid code above endds the program if a all 4 inputs arent between 1-8 and if an invalid input was sent.
    return 0;}

   *one=w; //sets memory address to valid input
    *two=x;
    *three=y;
    *four=z;

    int perf1 = 0; //initializes ints to represent perfect matches
    int perf2 = 0;
    int perf3 = 0;
    int perf4 = 0;

    int perfcount = 0;
    int wrongcount = 0; //initialize perfect and wrong spot chars
    if(w==solution1){ //for each variable, if its correct add 1 to perf count
     perfcount++;
    perf1 = 1;}
    
    if(x==solution2){
     perfcount++;
    perf2 = 1;}
   
    if(y==solution3){
     perfcount++;
    perf3 = 1;}
  
    if(z==solution4){
     perfcount++;
    perf4 = 1;}

    int wrong1, wrong2, wrong3, wrong4; //adds wrong to help check and compare perfect inputs to wrong spot inputs
    wrong1 = perf1;
    wrong2 = perf2;
    wrong3 = perf3; 
    wrong4 = perf4;
    if((wrong1 == 0) && (perf2 == 0) && (w==solution2) ){ //if both numbers being compared arent used, and are in a diff spot, add one to wrong count
       perf2 = 1; 
       wrong1 = 1;
       wrongcount++;}
    else  if((wrong1 == 0) && (perf3 == 0) && (w==solution3) ){
       perf3 = 1; 
       wrong1 = 1;
       wrongcount++;}
    else  if((wrong1 == 0) && (perf4 == 0) && (w==solution4) ){
       perf4 = 1; 
       wrong1 = 1;
       wrongcount++;}




    if((wrong2 == 0) && (perf1 == 0) && (x==solution1) ){//if both numbers being compared arent used, and are in a diff spot, add one to wrong count
       perf1 = 1; 
       wrong2 = 1;
       wrongcount++;}
    else  if((wrong2 == 0) && (perf3 == 0) && (x==solution3) ){
       perf3 = 1; 
       wrong2 = 1;
       wrongcount++;}
    else  if((wrong2 == 0) && (perf4 == 0) && (x==solution4) ){
       perf4 = 1; 
       wrong2 = 1;
       wrongcount++;}





    if((wrong3 == 0) && (perf2 == 0) && (y==solution2) ){//if both numbers being compared arent used, and are in a diff spot, add one to wrong count
       perf2 = 1;
       wrong3 = 1; 
       wrongcount++;}
    else  if((wrong3 == 0) && (perf1 == 0) && (y==solution1) ){
       perf1 = 1; 
       wrong3 = 1; 
       wrongcount++;}
    else  if((wrong3 == 0) && (perf4 == 0) && (y==solution4) ){
       perf4 = 1; 
       wrong3 = 1; 
       wrongcount++;}




    if((wrong4 == 0) && (perf2 == 0) && (z==solution2) ){//if both numbers being compared arent used, and are in a diff spot, add one to wrong count
       perf2 = 1; 
       wrong4 = 1; 
       wrongcount++;}
    else  if((wrong4 == 0) && (perf3 == 0) && (z==solution3) ){
       perf3 = 1; 
       wrong4 = 1;
       wrongcount++;}
    else  if((wrong4 == 0) && (perf1 == 0) && (z==solution1) ){
       perf1 = 1; 
       wrong4 = 1;
       wrongcount++;}

    
    printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n", guess_number, perfcount, wrongcount); //print code
    guess_number++; //incriment counter of guesses
=======
>>>>>>> release/main
=======
>>>>>>> release/main
    return 1;
}


