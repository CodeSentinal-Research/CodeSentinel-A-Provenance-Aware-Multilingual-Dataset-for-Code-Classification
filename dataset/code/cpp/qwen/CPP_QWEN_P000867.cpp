#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int xorVal = x ^ y;
    int count = 0;
    while (xorVal) {
        count += xorVal & 1;
        xorVal >>= 1;
    }
    cout << count << endl;
    return 0;
}
