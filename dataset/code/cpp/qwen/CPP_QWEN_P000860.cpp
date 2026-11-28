#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    int mask = 1;
    while (mask <= N) mask <<= 1;
    mask -= 1;
    cout << (N ^ mask) << endl;
    return 0;
}
