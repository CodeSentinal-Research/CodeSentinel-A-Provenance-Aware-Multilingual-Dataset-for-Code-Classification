Here is the C++ code for the problem:

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int prev;
    cin >> prev;

    int even_start = 0, odd_start = 0, max_len = 0;

    for (int i = 1; i < n; ++i) {
        int curr;
        cin >> curr;

        if ((prev % 2 == curr % 2) && (curr % 2 == 0)) {
            even_start = i;
        } else if (curr % 2 == 0) {
            max_len = max(max_len, even_start);
            even_start = i;
        }

        odd_start = max_len;
    }

    max_len = max(max_len, even_start);

    cout << max_len;

    return 0;
}

This code works by keeping track of the starting index of an alternating sequence of even numbers and odd numbers. If the previous number and the current number have the same parity and the current number is even, we update the starting index for the alternating sequence of even numbers. If the current number is even, we update the maximum length if necessary and start a new alternating sequence of even numbers.