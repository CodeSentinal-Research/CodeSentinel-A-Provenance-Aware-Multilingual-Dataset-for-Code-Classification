#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long N;
    cout << "Enter a non-negative integer N: ";
    cin >> N;

    long long smallest = N;
    long long largest = N;

    while (N) {
        smallest = min(smallest, N % 10);
        largest = max(largest, N % 10);
        N /= 10;
    }

    cout << "Smallest digit is: " << smallest << endl;
    cout << "Largest digit is: " << largest << endl;

    return 0;
}