#include <iostream>
using namespace std;

int reverse(int x) {
    int res = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + pop;
    }
    return res;
}

int main() {
    int x;
    cin >> x;
    cout << reverse(x) << endl;
    return 0;
}