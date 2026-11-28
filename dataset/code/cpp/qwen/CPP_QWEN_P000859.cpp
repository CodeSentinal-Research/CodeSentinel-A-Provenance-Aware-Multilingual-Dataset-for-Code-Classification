#include <iostream>
using namespace std;

int main() {
    unsigned int N;
    cin >> N;
    unsigned int res = 0;
    for (int i = 0; i < 32; ++i) {
        res <<= 1;
        res |= (N & 1);
        N >>= 1;
    }
    cout << res << endl;
    return 0;
}
