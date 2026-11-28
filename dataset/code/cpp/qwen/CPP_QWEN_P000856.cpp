#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    if (N == 0) {
        cout << 32 << endl; // Or 64 depending on type, assuming 32-bit int context usually
        return 0;
    }
    int count = 0;
    while (!(N & 1)) {
        count++;
        N >>= 1;
    }
    cout << count << endl;
    return 0;
}
