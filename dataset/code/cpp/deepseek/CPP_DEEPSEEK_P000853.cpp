Here is the code:

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter an integer N: ";
    cin >> N;
    cout << "Enter an integer K: ";
    cin >> K;

    int mask = 1 << K;
    int result = N ^ mask;

    cout << "The modified integer is: " << result;

    return 0;
}

This code first takes an integer `N` and an integer `K` as inputs. Then it uses bitwise XOR operation to toggle the K-th bit. The mask is created by shifting one bit left by K places. This mask is 1 followed by K bits which when XOR'd with `N` results in the original number.