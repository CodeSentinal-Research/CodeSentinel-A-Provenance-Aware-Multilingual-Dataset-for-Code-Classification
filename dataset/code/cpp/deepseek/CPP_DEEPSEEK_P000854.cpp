#include <iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    if (n < 0 || n > 2147483647) {
        cout << "Invalid input. Please enter an integer in the range 0 <= N <= 2^31 - 1";
        return 1;
    }
    cout << "Number of set bits: " << countSetBits(n);
    return 0;
}