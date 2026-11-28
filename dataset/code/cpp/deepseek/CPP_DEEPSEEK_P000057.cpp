#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;

    int sum = N * (N + 1);

    cout << "The sum of the first " << N << " odd numbers is: " << sum << endl;

    return 0;
}