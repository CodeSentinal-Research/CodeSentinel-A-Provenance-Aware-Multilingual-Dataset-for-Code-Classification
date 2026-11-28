#include <iostream>
using namespace std;

bool isPrime(int N) {
    if (N <= 1) 
        return false;
    if (N == 2) 
        return true;
    if (N % 2 == 0)
        return false;

    for (int i = 3; i * i <= N; i += 2) {
        if (N % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;

    if (N < 1 || N > 1000000000) {
        cout << "Invalid input" << endl;
        return 0;
    }

    if (isPrime(N)) 
        cout << "Prime" << endl;
    else 
        cout << "Not Prime" << endl;

    return 0;
}