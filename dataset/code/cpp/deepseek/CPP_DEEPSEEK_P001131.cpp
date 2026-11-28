#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter an integer N: ";
    cin >> N;
    if(N < 0 || N > 90) {
        cout << "Invalid input, N must be between 0 and 90";
        return 0;
    }

    int a = 0;
    int b = 1;
    int fib = 0;

    for(int i = 2; i <= N; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    cout << "The " << N << "th Fibonacci number is: " << fib << endl;

    return 0;
}