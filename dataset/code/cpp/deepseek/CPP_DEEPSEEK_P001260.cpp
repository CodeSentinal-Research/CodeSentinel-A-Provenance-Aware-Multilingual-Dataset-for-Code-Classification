#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A < B && B < C) {
        cout << "aabc";
    }
    else if (B < A && A < C) {
        cout << "abbc";
    }
    else if (C < A && A < B) {
        cout << "acbc";
    }
    else {
        cout << "Not possible";
    }

    return 0;
}