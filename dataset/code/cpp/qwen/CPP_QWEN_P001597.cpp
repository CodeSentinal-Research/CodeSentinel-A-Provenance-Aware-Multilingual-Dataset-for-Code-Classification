#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int q;
    cin >> q;
    
    // Precompute prefix counts for each value? Too much memory if values large.
    // Offline queries or Mo's algorithm?
    // Given constraints, simple prefix map for each query value if Q small?
    // Or just iterate for each query if N*Q is acceptable? 10^10 too big.
    
    // Use map of vectors for positions
    unordered_map<int, vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        positions[nums[i]].push_back(i);
    }
    
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        
        if (positions.find(x) == positions.end()) {
            cout << 0 << endl;
            continue;
        }
        
        auto& vec = positions[x];
        int leftIdx = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int rightIdx = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        
        cout << rightIdx - leftIdx << endl;
    }
    
    return 0;
}
