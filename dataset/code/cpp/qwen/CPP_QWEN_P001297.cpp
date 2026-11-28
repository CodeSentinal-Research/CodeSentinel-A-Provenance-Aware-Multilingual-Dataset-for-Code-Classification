#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    
    int sumA = accumulate(A.begin(), A.end(), 0);
    
    // Find max gain from swapping
    int maxGain = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (B[j] > A[i]) {
                maxGain = max(maxGain, B[j] - A[i]);
            }
        }
    }
    
    cout << sumA + maxGain << endl;
    return 0;
}
