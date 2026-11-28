#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int ones = 0;
    int zeros = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            ones++;
        } else {
            zeros++;
        }
    }

    int maxLength = max(ones, zeros) * 2;

    cout << maxLength;

    return 0;
}