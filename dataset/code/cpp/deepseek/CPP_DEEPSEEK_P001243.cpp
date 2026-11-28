#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int five = n / 5;
        int remaining = n % 5;
        while (five >= 1) {
            if (five % 3 == 0) {
                cout << "YES" << endl;
                break;
            }
            five--;
        }
        if (remaining == 4) {
            if (five == 0) {
                cout << "NO" << endl;
            } else {
                five--;
                remaining += 5;
                if (five >= 1 && (five % 3 == 0 || remaining % 3 == 0)) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

This code works by first reading the number of test cases, then for each test case, it reads the number of notes and checks if it is divisible by 5 or not. If it is divisible, it breaks out of the loop and prints "YES". If it isn't divisible, it subtracts 1 from the total and checks again. If the remaining amount is divisible by 3, it prints "YES". If it isn't divisible and the remaining amount is not divisible by 3, it prints "NO". This process is repeated for each test case.