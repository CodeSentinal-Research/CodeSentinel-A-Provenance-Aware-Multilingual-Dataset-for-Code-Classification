#include <iostream>
using namespace std;

int main() {
    int start, goal;
    cin >> start >> goal;
    int xorVal = start ^ goal;
    int count = 0;
    while (xorVal) {
        count += xorVal & 1;
        xorVal >>= 1;
    }
    cout << count << endl;
    return 0;
}
