#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    if(N <= 0 || N > 1000000000) {
        cout << "Invalid input! Please enter a positive integer N (1 <= N <= 10^9)";
        return 0;
    }

    int sum = N * (N + 1) / 2;

    cout << "The sum of the first " << N << " natural numbers is " << sum << endl;

    return 0;
}