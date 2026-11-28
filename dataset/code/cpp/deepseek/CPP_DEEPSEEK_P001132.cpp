Here is the code for the given problem in C++:

#include <iostream>
using namespace std;

int countWays(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;

    int a = 1;
    int b = 2;
    int c = 0;

    for (int i = 3; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    if (n < 1 || n > 45) {
        cout << "Invalid input";
        return 0;
    }

    cout << "Number of ways = " << countWays(n);

    return 0;
}
This program will prompt the user for the number of steps. If the input is invalid (i.e., not between 1 and 45), it will print "Invalid input". Otherwise, it will calculate and print the number of distinct ways to reach the top of the staircase with `n` steps.