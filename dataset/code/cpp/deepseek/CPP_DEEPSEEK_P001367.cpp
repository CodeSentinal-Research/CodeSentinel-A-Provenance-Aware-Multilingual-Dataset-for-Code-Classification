#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    if (K <= N/2) {
        cout << "FIRST\n";
    } else {
        cout << "SECOND\n";
    }
    return 0;
}