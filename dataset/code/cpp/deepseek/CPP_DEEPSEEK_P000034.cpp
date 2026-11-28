Here is the complete C++ code:

#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    int sum = 0;
    for(int i = 1; i <= N; i++) {
        if(i % 2 != 0) {
            sum += i;
        }
    }

    cout << "The sum of odd numbers up to N is: " << sum << endl;

    return 0;
}

This program takes an input `N`, then calculates the sum of all odd numbers up to `N`. It does this by initializing a variable `sum` to 0 and then iterating over all numbers from 1 to `N`. If the current number is odd (i.e., `i % 2 != 0`), it is added to `sum`. Finally, the sum is printed out.