Here is a simple C++ code for the problem:

#include <iostream>

using namespace std;

int findSmallestSolution(int n) {
    if (n <= 0 || n > 15) {
        cout << "Invalid input" << endl;
        return -1;
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i * ((i - 1) % n) == 1) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of congruences: ";
    cin >> n;
    
    int solution = findSmallestSolution(n);
    
    if (solution != -1) {
        cout << "The smallest non-negative solution is: " << solution << endl;
    }
    
    return 0;
}
This program first gets the input from the user. If the user input is not within the given constraints (1 <= n <= 15), it prints an error message and returns -1. Otherwise, it iterates from 1 to n, checking if the product of the current number and (current number - 1) mod n is 1. If it finds such a number, it returns it as the smallest non-negative solution. If no such number is found, it returns -1.