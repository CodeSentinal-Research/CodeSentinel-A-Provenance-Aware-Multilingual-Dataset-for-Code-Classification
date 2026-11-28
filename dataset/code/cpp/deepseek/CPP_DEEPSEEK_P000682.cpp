Here is the C++ code:

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int main(){
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;

    if(n < 0) {
        cout << "Invalid input. Please enter a non-negative integer.";
        return 0;
    }

    cout << "Factorial of " << n << " is " << factorial(n);
    return 0;
}
This code first declares a function factorial that calculates the factorial of a number using recursion. In the main function, it takes an integer input from the user, checks if it's a non-negative integer, and then calls the factorial function with this input. If the input is invalid, it will print an error message and return 0.