#include <iostream>
using namespace std;

int countLeadingZeros(unsigned int N) {
    int count = 0;
    while ((N & 1) == 0) {
        N >>= 1;
        count++;
    }
    return count;
}

int main() {
    unsigned int N;
    cout << "Enter an unsigned integer: ";
    cin >> N;
    cout << "Number of leading zeros: " << countLeadingZeros(N) << endl;
    return 0;
}