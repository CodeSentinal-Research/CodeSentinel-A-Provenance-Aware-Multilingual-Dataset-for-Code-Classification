Here is the C++ code that solves the problem:

#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << source << " to rod " << destination << endl;
        return;
    }
    TowerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    TowerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "Invalid input. Please enter a number between 1 and 20.";
        return 0;
    }
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}

This program uses recursion to solve the Tower of Hanoi problem. The TowerOfHanoi function is a recursive function that moves the disks from the source rod to the destination rod. The auxiliary rod is used as a buffer. The base case is when there is only one disk to move, which is a one-move move. The recursive case is when there are more disks to move. The function first moves the n-1 disks from the source to the auxiliary rod, then moves the nth disk from the source to the destination, and finally moves the n-1 disks from the auxiliary rod to the destination.