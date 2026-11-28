#include <iostream>
using namespace std;

int main() {
    int n, first;
    cin >> n >> first;

    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        first ^= temp;
    }

    cout << first;

    return 0;
}