#include <iostream>
using namespace std;

int main() {
    long long N;
    cout << "Enter a non-negative decimal integer: ";
    cin >> N;
    
    if (N < 0) {
        cout << "Invalid input, please enter a non-negative integer." << endl;
        return 0;
    }

    long long binary = 0;
    int count = 0;
    while (N > 0) {
        int remainder = N % 2;
        N /= 2;
        binary += remainder * pow(2, count);
        ++count;
    }

    cout << "The binary representation of the given decimal integer is: " << binary << endl;
    return 0;
}