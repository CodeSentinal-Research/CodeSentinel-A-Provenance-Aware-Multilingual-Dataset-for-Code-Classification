#include <iostream>
using namespace std;

int main() {
    int N, K;
    cout << "Enter the integer N: ";
    cin >> N;
    cout << "Enter the integer K: ";
    cin >> K;
    if(K >= 0 && K <= 31) {
        N = N | (1 << K);
    }
    else {
        cout << "Invalid input for K, must be between 0 and 31" << endl;
        return 0;
    }
    cout << "Modified integer: " << N << endl;
    return 0;
}