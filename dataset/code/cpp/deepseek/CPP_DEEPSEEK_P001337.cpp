Here is a simple C++ code that solves the problem:

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N < 1 || N > 15) {
        cout << "Invalid input" << endl;
        return 0;
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        bool isBeautiful = true;
        for (int j = 1; j <= N; j++) {
            if ((j % i == 0) || (i % j == 0)) {
                isBeautiful = false;
                break;
            }
        }
        if (isBeautiful) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
In this code, we are iterating over all numbers from 1 to N and checking each number to see if it is divisible by any other number. If it is divisible, we set `isBeautiful` to `false` and break the loop. If `isBeautiful` is still `true` after the loop, we increment the count. At the end, we print the count.