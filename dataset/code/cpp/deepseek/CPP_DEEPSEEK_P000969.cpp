#include <iostream>
using namespace std;

int fibonacci(int N) {
    if(N <= 1) return N;
    else return fibonacci(N-1) + fibonacci(N-2);
}

int main() {
    int N;
    cout << "Enter an integer N: ";
    cin >> N;
    
    if(N < 0 || N > 1000000) {
        cout << "Invalid input. Please enter a number between 0 and 10^6." << endl;
        return 0;
    }
    
    cout << "The " << N << "th Fibonacci number is: " << fibonacci(N) << endl;
    return 0;
}