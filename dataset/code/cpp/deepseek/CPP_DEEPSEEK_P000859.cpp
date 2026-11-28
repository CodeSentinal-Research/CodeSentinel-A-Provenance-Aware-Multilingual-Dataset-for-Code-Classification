#include <iostream>
using namespace std;

int reverseBits(unsigned int N) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        if (N & 1) {
            result++;
        }
        N >>= 1;
    }
    return result;
}

int main() {
    unsigned int N;
    cout << "Enter an unsigned integer: ";
    cin >> N;

    if (cin.fail()) {
        cout << "Invalid input! Please enter an unsigned integer." << endl;
        return 0;
    }

    unsigned int reversed = reverseBits(N);
    cout << "Reversed integer is: " << reversed << endl;

    return 0;
}