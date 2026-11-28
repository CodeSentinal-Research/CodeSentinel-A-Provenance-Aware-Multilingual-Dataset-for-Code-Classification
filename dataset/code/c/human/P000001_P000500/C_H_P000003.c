#include <stdio.h>


// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}



int main() {
    int f = 8;
    int g = 3;

    
    int product = multiply(f, g);
    
    
    printf("The product of %d and %d is: %d\n", f, g, product);
    

    return 0;
}
