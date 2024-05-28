<<<<<<< HEAD
<<<<<<< HEAD
//gsayy2 and noahlr2
#include <stdlib.h>
#include <stdio.h>
/*INTRO PARAGRAPH:
ERROR 1: 
Second and third return in is_prime are flipped. This causes inaccuracies where
prime numbers will return a 0 and non primes will return a 1.

ERROR 2:
One Line was originally k=i%j; when in reality it should be k = i/j;
the effect this line is supposed to have is it is supposed to set k equal to 
i, which is one of the numbers in between a and b, and divide it by j, which 
allows k to take the value of a potential prime number. using % instead of /
is wrong because then you're using the remainder, which should always be 0,
instead of the quotient for isprime.

Error 3:
add a break after the printing of i. This will terminate the for loop using
int j. This is supposed to terminate because if i is already printed, you know
i was a valid semiprime so you can move onto checking if another number is a semi
prime.


*/
=======
#include <stdlib.h>
#include <stdio.h>

>>>>>>> release/main
=======
#include <stdlib.h>
#include <stdio.h>

>>>>>>> release/main

/*
 * is_prime: determines whether the provided number is prime or not
 * Input    : a number
 * Return   : 0 if the number is not prime, else 1
 */
int is_prime(int number)
{
    int i;
    if (number == 1) {return 0;}
    for (i = 2; i < number; i++) { //for each number smaller than it
        if (number % i == 0) { //check if the remainder is 0
<<<<<<< HEAD
<<<<<<< HEAD
            return 0;
        }
    }
    return 1;
=======
=======
>>>>>>> release/main
            return 1;
        }
    }
    return 0;
<<<<<<< HEAD
>>>>>>> release/main
=======
>>>>>>> release/main
}


/*
 * print_semiprimes: prints all semiprimes in [a,b] (including a, b).
 * Input   : a, b (a should be smaller than or equal to b)
 * Return  : 0 if there is no semiprime in [a,b], else 1
 */
int print_semiprimes(int a, int b)
{
    int i, j, k;
    int ret = 0;
    for (i = a; i <=b; i++) { //for each item in interval
        //check if semiprime
        for (j = 2; j <= i; j++) {
            if (i%j == 0) {
                if (is_prime(j)) {
<<<<<<< HEAD
<<<<<<< HEAD
    
                    k = i/j;
                    if (is_prime(k)) {
                        printf("%d ", i);
                       break;
=======
                    k = i%j;
                    if (is_prime(k)) {
                        printf("%d ", i);
>>>>>>> release/main
=======
                    k = i%j;
                    if (is_prime(k)) {
                        printf("%d ", i);
>>>>>>> release/main
                    }
                }
            }
        }

    }
    printf("\n");
    return ret;

}
