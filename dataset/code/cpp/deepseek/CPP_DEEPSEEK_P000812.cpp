#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    if (num < 1) return false;
    int left = 1, right = num, ans = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid * mid == num) {
            return true;
        }
        if (mid * mid < num) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int num;
    cin >> num;
    if (isPerfectSquare(num)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}