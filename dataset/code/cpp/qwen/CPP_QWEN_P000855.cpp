#include <iostream>
using namespace std;

int main() {
    unsigned int N;
    cin >> N;
    if (N == 0) {
        cout << 32 << endl;
        return 0;
    }
    int count = 0;
    while (!(N & (1U << 31))) {
        count++;
        N <<= 1;
    }
    cout << count << endl;
    return 0;
}
