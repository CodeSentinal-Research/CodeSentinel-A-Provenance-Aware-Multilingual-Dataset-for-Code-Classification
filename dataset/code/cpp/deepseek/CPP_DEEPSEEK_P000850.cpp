#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter K: ";
    cin >> K;
    if ((N & (1 << (K - 1))) == 0) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}