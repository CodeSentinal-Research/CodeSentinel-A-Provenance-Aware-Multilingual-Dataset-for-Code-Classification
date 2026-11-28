Here is the C++ code for the problem:

#include <iostream>
using namespace std;

bool areCoprime(int a, int b) {
    if (a == 0) {
        return b == 0;
    }
    if (b == 0) {
        return a == 0;
    }
    return (a % b == 0 || b % a == 0);
}

int main() {
    int N, L, R;
    cout << "Enter two integers: ";
    cin >> N >> L >> R;
    int count = 0;
    for (int i = L; i <= R; i++) {
        if (areCoprime(N, i)) {
            count++;
        }
    }
    cout << "Count of integers coprime with " << N << " is " << count << endl;
    return 0;
}
This code first takes three integers as input, then it counts how many integers between L and R are coprime with N. The function `areCoprime(int a, int b)` is used to check if two numbers are coprime. It returns true if the two numbers are coprime and false otherwise. In the `main()` function, it iterates through all the numbers from L to R, and for each number, it checks if it is coprime with N. If it is, it increments the count. Finally, it prints the count of integers coprime with N.