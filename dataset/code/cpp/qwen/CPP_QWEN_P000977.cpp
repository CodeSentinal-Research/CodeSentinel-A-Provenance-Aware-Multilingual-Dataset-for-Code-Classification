#include <iostream>
using namespace std;

int main() {
    long long x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // Area should be 0
    long long val = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    cout << (val == 0 ? "true" : "false") << endl;
    return 0;
}
