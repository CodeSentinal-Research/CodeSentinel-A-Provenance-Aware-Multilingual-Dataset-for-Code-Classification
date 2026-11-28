Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;
        L--; R--;  
        int xorVal = 0;
        for (int j = L; j <= R; j++) {
            xorVal ^= A[j];
        }
        cout << xorVal << endl;
    }
    return 0;
}

This code reads the array A and the queries Q, then it prints the XOR of all the elements in the specified range for each query.