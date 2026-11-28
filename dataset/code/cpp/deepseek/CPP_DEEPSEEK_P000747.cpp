#include <iostream>
using namespace std;

long int countWays(int n) {
    if (n <= 1)
        return n;
    long int first = 1, second = 1, third = 0;
    for (int i = 2; i <= n; i++) {
        third = first + second;
        second = first;
        first = third;
    }
    return third;
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    if (n <= 0 || n > 40) {
        cout << "Invalid input, please enter a number between 1 and 40.";
        return 0;
    }
    cout << "Total ways to climb: " << countWays(n);
    return 0;
}