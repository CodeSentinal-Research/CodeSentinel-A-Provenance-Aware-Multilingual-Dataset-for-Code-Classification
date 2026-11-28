#include <iostream>
using namespace std;

void generateBits(int n, int last_bit, string str) {
    if (n == 0) {
        cout << str << endl;
        return;
    }

    if (last_bit == 0) {
        generateBits(n - 1, 0, str + '0');
    } else if (last_bit == 1) {
        if (n == 1) {
            cout << str + '1' << endl;
        } else {
            generateBits(n - 1, 0, str + '0');
            generateBits(n - 1, 1, str + '1');
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 2; i++) {
        generateBits(n, i, to_string(i));
    }

    return 0;
}