#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// 1.1 Entremos en calor

/* 
Escribir la función que dado n en N devuelve si es primo.
Recuerden que un número es primo si los únicos divisores que tiene son 1 y el mismo.
*/

bool is_prime( int n ) {
    if (n <= 0 || n == 1) {
        return false;
    }
    for ( int i = 2; i <= sqrt(n); ++i ) {
        if ( n % i == 0 ) {
            return false;
        }
    }
    return true;
}


/* 
Escribir la función que daado n en N, devuelve la suma de todos los  números impares menors que n.
*/

int sum_of_odds( int n ) {
    int result = 0;
    for ( int i = 1; i < n; ++i ) {
        if( ( i % 2 ) != 0 ) {
            result += i;
        }
    }
    return result;
}

int main() {
    int number;
    number = 7;

    if (is_prime(7)) {
        printf("%d is a prime number.\n", number);
    } else {
        printf("%d is not a prime number.\n", number);
    }

    int n = 7;
    int sum = sum_of_odds(n);
    printf("Sum of prime numbers up to %d is: %d\n", n, sum);

    return 0;
}