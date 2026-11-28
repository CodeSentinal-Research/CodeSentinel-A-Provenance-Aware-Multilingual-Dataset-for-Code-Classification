/**
 * Fibonacci series and even Fibonacci numbers.
 */

#include <stdio.h>

#define LIMIT 4000000

/**
 * Print fibonacci series less than LIMIT.
 *
 * @param int a
 * @param int b
 *
 * @return void
 */
void print_fibonacci_series(int a, int b)
{
    int sum = a + b;

    if (sum > LIMIT) {
        return;
    }

    printf("%d ", sum);

    print_fibonacci_series(b, sum);
}

/**
 * Print N fibonacci series.
 *
 * @param int n
 *
 * @return unsigned long
 */
unsigned long num_fibonacci(int n)
{
    if (n < 2) {
        return (unsigned long) n;
    }

    return num_fibonacci(n - 1) + num_fibonacci(n - 2);
}

/**
 * Get sum of even fibonacci series up to LIMIT.
 *
 * @param int a
 * @param int b
 * @param int c
 *
 * @return unsigned long
 */


int main()
{
    int limit;

    print_fibonacci_series(-1, 1);


    printf("\n\nEnter N to print N fibonacci numbers: ");
    scanf("%d", &limit);

    for (int i = 0; i < limit; i++) {
        printf("%lu ", num_fibonacci(i));
    }

    return 0;
}
