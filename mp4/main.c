<<<<<<< HEAD
<<<<<<< HEAD
//gsayy2 and noahlr2
=======
>>>>>>> release/main
=======
>>>>>>> release/main
#include <stdlib.h>
#include <stdio.h>
#include "semiprime.h"

<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> release/main
=======

>>>>>>> release/main
/*
    Main function: checks for valid inputs and runs the print_semiprimes function.
    Inputs: none
    Outputs: if provided a,b are invalid, returns -1. If there were no
    semiprimes in the range, returns 0. If there were semiprimes, returns 1.
*/
int main(){
   int a, b, ret;
<<<<<<< HEAD
<<<<<<< HEAD
   ret = 0;
=======
>>>>>>> release/main
=======
>>>>>>> release/main
   printf("Input two numbers: ");
   scanf("%d %d", &a, &b);
   if( a <= 0 || b <= 0 ){
     printf("Inputs should be positive integers\n");
     return -1;
   }

   if( a > b ){
     printf("The first number should be smaller than or equal to the second number\n");
     return -1;
   }

<<<<<<< HEAD
<<<<<<< HEAD
   ret = print_semiprimes(a, b);
=======
   ret = print_semiprimes(a, b)
>>>>>>> release/main
=======
   ret = print_semiprimes(a, b)
>>>>>>> release/main
   return ret;
}
