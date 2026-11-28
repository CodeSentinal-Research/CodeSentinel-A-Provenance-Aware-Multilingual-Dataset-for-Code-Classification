#include <iostream>
using namespace std;

void decToBinary(long long n, long long base) {
    if (n / base) {
        decToBinary(n / base, base);
    }
    cout << n % base;
}

int main() {
    long long n;
    cout << "Enter an integer: ";
    cin >> n;
    
    if (n < 0 || n > 10000000000000000) {
        cout << "Invalid input! Number must be in the range 0 to 10^18";
        return 0;
    }
    
    decToBinary(n, 2);
    cout << "\n";
    return 0;
}
This code uses a recursive function to convert the input decimal number to binary. It first divides the number by 2 until the number becomes 0, then it outputs the remainder. The remainder is the binary digit, and this process is repeated until all digits are printed.