Here is the C++ code for your problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    int first = 0;
    int second = 1;
    int next;

    cout << first << " " << second << " "; 

    for (int i = 2; i < N; i++) {
        next = first + second;
        first = second;
        second = next;
        cout << next << " ";
    }

    return 0;
}

This program will ask the user to enter a positive integer N. It will then print the first N numbers in the Fibonacci series. The Fibonacci series is a sequence where each number is the sum of the two preceding ones, usually starting with 0 and 1.