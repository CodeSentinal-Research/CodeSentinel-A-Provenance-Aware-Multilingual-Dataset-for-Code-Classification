#include <iostream>
using namespace std;

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = n + slow * slow;
        fast = n + fast * fast;
        fast = n + fast * fast;
    } while (slow != fast);

    return slow == 1;
}

int main() {
    int n;
    cin >> n;
    if (isHappy(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}