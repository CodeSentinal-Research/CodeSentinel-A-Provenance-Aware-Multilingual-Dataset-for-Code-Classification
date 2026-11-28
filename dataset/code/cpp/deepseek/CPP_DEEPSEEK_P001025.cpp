#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N < 1) {
        cout << "Invalid input";
        return 0;
    }
    int leafNodes = 0;
    int internalNodes = 0;
    for (int i = 1; i <= N; i++) {
        if (i == 1 || i == 2) {
            leafNodes++;
        } else {
            internalNodes++;
        }
    }
    cout << internalNodes;
    return 0;
}