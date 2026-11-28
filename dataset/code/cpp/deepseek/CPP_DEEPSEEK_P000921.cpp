Here is the C++ code for your problem:

#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N < 0 || N > 1000000000000) {
        cout << "Invalid input";
        return 0;
    }

    long long freq[10] = {0};
    while (N) {
        freq[N % 10]++;
        N /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << freq[i] << " ";
    }

    return 0;
}
This code will take an integer input N, and then count the frequency of each digit in the number. The frequency of each digit is stored in an array `freq[]`. The code will keep dividing N by 10 and incrementing the corresponding index in the `freq[]` array until N becomes 0. The final frequencies will be printed out.