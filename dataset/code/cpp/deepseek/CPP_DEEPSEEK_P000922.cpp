#include <iostream>

using namespace std;

int main() {
    long long L, R;
    cin >> L >> R;

    long long total = 0;

    for (long long i = L; i <= R; i++) {
        total += i;
    }

    cout << total;

    return 0;
}