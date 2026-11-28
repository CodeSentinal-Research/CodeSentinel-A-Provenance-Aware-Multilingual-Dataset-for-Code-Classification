#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int operations = 0;
    while (y != x) {
        if (y < x) {
            y = x - y;
        } else {
            y = (y - x) / 2;
        }
        operations++;
    }

    cout << operations << endl;

    return 0;
}