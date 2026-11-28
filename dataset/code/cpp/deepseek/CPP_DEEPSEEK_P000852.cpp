Here's the code:

#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter a number and the k-th bit you want to clear (0 <= K <= 31): ";
    cin >> N >> K;
    N = N & ~(1 << K);
    cout << "The modified number is: " << N << endl;
    return 0;
}
This program uses bitwise AND operator (`&`) with a binary representation of the K-th bit set to 0. It then prints out the result.