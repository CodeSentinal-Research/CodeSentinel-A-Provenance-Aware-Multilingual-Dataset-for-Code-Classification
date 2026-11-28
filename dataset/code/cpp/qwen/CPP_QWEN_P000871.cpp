#include <iostream>
using namespace std;

int main() {
    long long left, right;
    cin >> left >> right;
    while (left < right) {
        right = right & (right - 1);
    }
    cout << right << endl;
    return 0;
}
