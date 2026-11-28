Here is the C++ code that solves the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;
    if (N < 1 || N > 1000) {
        cout << "Invalid input! Please enter a number between 1 and 1000." << endl;
        return 0;
    }
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i * i;
    }
    cout << "The sum is: " << sum << endl;
    return 0;
}
This program first takes an input number N from the user. It then checks if the input is within the valid range (1 ≤ N ≤ 1000). If not, it prints an error message and returns.

If the input is valid, it calculates the sum of the squares of the first N natural numbers (1² + 2² + ... + N²). The sum is stored in the variable sum, and is printed out at the end.