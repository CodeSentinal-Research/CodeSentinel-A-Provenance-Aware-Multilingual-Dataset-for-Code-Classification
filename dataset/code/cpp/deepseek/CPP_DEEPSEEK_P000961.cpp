Here is the C++ code to solve the problem:

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long A, B, C;
    long long X1, Y1, X2, Y2;

    cout << "Enter the range for A: ";
    cin >> A;
    cout << "Enter the range for B: ";
    cin >> B;
    cout << "Enter the range for C: ";
    cin >> C;
    cout << "Enter the range for X (X1, X2): ";
    cin >> X1 >> X2;
    cout << "Enter the range for Y (Y1, Y2): ";
    cin >> Y1 >> Y2;

    long long valid_solutions = 0;
    for (long long i = X1; i <= X2; i++) {
        for (long long j = Y1; j <= Y2; j++) {
            if (A * i + B * j == C) {
                valid_solutions++;
            }
        }
    }

    cout << "Number of valid solutions: " << valid_solutions << endl;

    return 0;
}

In this code, we first take input for A, B, C ranges for X and Y. Then we iterate over X and Y from the given ranges, and for each pair, check if AX + BY equals C. If it does, we increment the valid_solutions counter. Finally, we print out the count of valid solutions.