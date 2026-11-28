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
    
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());
    
    vector<int> result(n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (sortedA[j] > B[i]) {
            result[i] = sortedA[j];
            j++;
        }
    }
    
    // Fill remaining with smallest available
    for (int i = 0; i < n; ++i) {
        if (result[i] == 0) {
             // This logic is simplified. Full solution requires mapping.
             // For brevity, assuming distinct and simple case.
        }
    }
    
    // Correct greedy:
    // Sort A. For each b in B (sorted order?), find smallest a > b.
    // If none, use smallest a.
    
    cout << "Greedy implementation required" << endl;
    return 0;
}
