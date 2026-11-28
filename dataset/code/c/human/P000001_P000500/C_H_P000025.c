#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


static int reverse(int x)
{
    int n = 0;
    while (x != 0) {
        int r = x % 10;
        /* Checking the over/underflow. */
        if (n > INT_MAX / 10 || (n == INT_MAX / 10 && r > 7)) {
            return 0;
        }
        if (n < INT_MIN / 10 || (n == INT_MIN / 10 && r < -8)) {
            return 0;
        }

        n = n * 10 + r;
        x /= 10;
    }
    return n;
}


int main(int argc, char**argv)
{
    
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test i\n");
        return 0;
    }
    printf("\n");
    int n = atoi(argv[1]); 
    printf("%12d  =>  %-12d  %s!\n",  n, reverse(n), reverse(reverse(n))==n ? "passed":"failed");
    return 0;
}
