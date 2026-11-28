#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int xor_arr[n];
    int xor_res = 0;

    for (int i = 0; i < n; i++) {
        cin >> xor_arr[i];
        xor_res ^= xor_arr[i];
    }

    int odd_sum = 0, even_sum = 0;
    for (int i = 0; i < n; i++) {
        if (xor_arr[i] % 2 == 0)
            even_sum += xor_arr[i];
        else
            odd_sum += xor_arr[i];
    }

    if (odd_sum % 2 == 0 && even_sum % 2 == 0)
        cout << xor_res << " " << (xor_res ^ odd_sum) << endl;
    else if (odd_sum % 2 == 1 && even_sum % 2 == 1)
        cout << (xor_res ^ even_sum) << " " << (xor_res ^ odd_sum ^ even_sum) << endl;
    else if (odd_sum % 2 == 1 && even_sum % 2 == 0)
        cout << (xor_res ^ odd_sum) << " " << (xor_res ^ odd_sum ^ even_sum) << endl;
    else if (odd_sum % 2 == 0 && even_sum % 2 == 1)
        cout << (xor_res ^ even_sum) << " " << (xor_res ^ odd_sum ^ even_sum) << endl;

    return 0;
}