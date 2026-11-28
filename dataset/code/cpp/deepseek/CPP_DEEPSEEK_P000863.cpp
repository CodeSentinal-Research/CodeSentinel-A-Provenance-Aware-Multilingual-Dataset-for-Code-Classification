#include <iostream>
using namespace std;

int main() {
    int n, i, j, k;
    int a[32];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    int xor_all = 0, res1 = 0, res2 = 0;
    for(i = 0; i < n; i++) {
        xor_all ^= a[i];
    }
    int set_bit = xor_all & -xor_all;
    for(i = 0; i < n; i++) {
        if(a[i] & set_bit) {
            res1 ^= a[i];
        } else {
            res2 ^= a[i];
        }
    }
    cout << "The two unique elements are " << res1 << " and " << res2 << endl;
    return 0;
}