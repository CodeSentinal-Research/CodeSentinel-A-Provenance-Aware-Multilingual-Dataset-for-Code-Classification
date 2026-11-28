#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int leafNodes = 0;
    for (int i = 1; i <= N; i++) {
        leafNodes += (i == N) ? 1 : 0;
    }

    cout << leafNodes << endl;

    return 0;
}