Sure, here is a simple C++ code snippet for the given problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;

    int number = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            cout << number << " ";
            number++;
        }
        cout << "\n";
    }

    return 0;
}
This program first prompts the user to input a positive integer. Then, it uses two nested loops to generate and print Floyd's triangle. The first loop runs from 0 to N, while the second loop runs from 0 to the current iteration of the first loop. Inside the second loop, it prints the current number and increments it by 1. After each line of the triangle, it prints a newline character to move to the next line.