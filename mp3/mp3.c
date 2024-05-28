<<<<<<< HEAD
<<<<<<< HEAD
/**noahlr2
 * 
 * 
 * This code takes an input N and prints out the pascals triangle row N. 
 **/
=======
>>>>>>> release/main
=======
>>>>>>> release/main
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row;

<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> release/main
=======
>>>>>>> release/main
  printf("Enter a row index: ");
  scanf("%d",&row);

  // Write your code here
<<<<<<< HEAD
<<<<<<< HEAD
    unsigned long value = 1; 
  for (int i =0; i <= row; i++){ //this will loop through every value
    if(i != 0){ //this allows the first value to always be 1, and then the logic starts after k = 0
        for(long j = 1; j <= i; j++) //i dont know why it needs to be a long but it does otherwise it wont compile, this does the multiplication for pi notation
            value =value* (row + 1-j)/j; //this is the pi notation equation
    }
    printf("%lu ", value); //print result
     value = 1; //resets value
  }
 return 0;}
=======

  return 0;
}
>>>>>>> release/main
=======

  return 0;
}
>>>>>>> release/main
