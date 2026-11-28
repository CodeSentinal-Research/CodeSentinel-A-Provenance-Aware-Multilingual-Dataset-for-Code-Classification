#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;
    int sum = N * (N + 1) / 2;
    cout << "Sum of first " << N << " natural numbers is: " << sum << endl;
    return 0;
}