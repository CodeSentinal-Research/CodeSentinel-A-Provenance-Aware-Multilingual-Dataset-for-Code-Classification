Here is the C++ code to solve the problem:

#include <iostream>
using namespace std;

int main() {
    long long A, B, N;
    cin >> A >> B >> N;

    if (A + B > N) {
        cout << "False";
    } else {
        cout << "True";
    }

    return 0;
}

This program reads the three inputs (A, B, N) from the standard input. It then checks if the sum of A and B is greater than or equal to N. If it is, it prints "False", otherwise it prints "True". This program assumes that the inputs will be integers and that they will fit within the limits specified by the problem.