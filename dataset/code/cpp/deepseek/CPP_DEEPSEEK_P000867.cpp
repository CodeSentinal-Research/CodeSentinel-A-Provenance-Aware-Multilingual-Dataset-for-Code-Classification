#include <iostream>
using namespace std;

int main() {
    int x, y;
    cout << "Enter two integers: ";
    cin >> x >> y;
    int count = 0;
    while (x > 0 || y > 0) {
        int x_last_bit = x & 1;
        int y_last_bit = y & 1;
        x >>= 1;
        y >>= 1;
        if (x_last_bit != y_last_bit) {
            count++;
        }
    }
    cout << "Hamming distance is: " << count << endl;
    return 0;
}