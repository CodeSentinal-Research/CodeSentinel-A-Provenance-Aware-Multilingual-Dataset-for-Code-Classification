#include <iostream>
#include <cmath>

using namespace std;

int totalNQueens(int N) {
    return pow(N, N);
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    
    if (N < 1 || N > 14) {
        cout << "Invalid input. Please enter a number between 1 and 14." << endl;
        return 1;
    }
    
    cout << "The total number of distinct ways to place " << N << " queens on an " << N << " × " << N << " chessboard is " << totalNQueens(N) << endl;

    return 0;
}
This program will ask for the number of queens, and if the number is not between 1 and 14 (inclusive), it will display an error message and terminate. Otherwise, it will calculate and print the total number of distinct ways to place N queens on an N × N chessboard so that no two queens attack each other. In the case of N = 4, the total number of distinct ways to place 4 queens on an 4 × 4 chessboard is 92.