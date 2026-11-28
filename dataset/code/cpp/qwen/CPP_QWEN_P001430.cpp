#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    
    vector<int> prefixCommon(n, 0);
    unordered_map<int, int> countA, countB;
    int common = 0;
    
    for (int i = 0; i < n; ++i) {
        countA[A[i]]++;
        countB[B[i]]++;
        if (countA[B[i]] > 0 && countB[B[i]] == 1) common++; // B[i] appeared in A before or now
        if (countB[A[i]] > 0 && countA[A[i]] == 1 && A[i] != B[i]) common++; // A[i] appeared in B before
        
        // Simpler logic:
        // Just track intersection size at each step
        common = 0;
        for(auto& p : countA) {
             if(countB.count(p.first)) common += min(p.second, countB[p.first]);
        }
        prefixCommon[i] = common;
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << prefixCommon[i];
    }
    cout << endl;
    return 0;
}
