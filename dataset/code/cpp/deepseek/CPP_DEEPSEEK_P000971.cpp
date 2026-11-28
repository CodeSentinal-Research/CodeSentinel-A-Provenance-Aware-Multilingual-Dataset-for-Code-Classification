Here is the C++ code for the given problem:

#include <iostream>
using namespace std;

int main() {
    int N, A, B, F0, F1, Fn;

    cout << "Enter the values of A, B, F0, F1, and N: ";
    cin >> A >> B >> F0 >> F1 >> N;

    for (int i = 2; i <= N; i++) {
        Fn = A * Fn1 + B * Fn2;
        Fn1 = Fn;
        Fn2 = Fn1;
    }

    cout << "The value of FN is: " << Fn << endl;

    return 0;
}

In this code, we are using a loop to calculate the values of Fn based on the recurrence relation. The variables `Fn1` and `Fn2` are used to store the last two Fn values to calculate the next one. We then update `Fn1` and `Fn2` after each iteration.