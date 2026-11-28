#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int or_ab = a | b;

    int xor_abc = or_ab ^ c;

    int count = 0;
    while (xor_abc) {
        count += xor_abc & 1;
        xor_abc >>= 1;
    }

    cout << count << endl;

    return 0;
}