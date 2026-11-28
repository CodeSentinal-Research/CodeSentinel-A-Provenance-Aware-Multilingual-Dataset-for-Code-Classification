#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    unordered_map<long long, int> prodCount;
    long long tuples = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long prod = (long long)nums[i] * nums[j];
            tuples += prodCount[prod];
            prodCount[prod]++;
        }
    }
    
    // Each pair of pairs (a,b) and (c,d) forms 8 tuples if indices distinct?
    // Problem says indices distinct.
    // If we have count C for a product, number of ways to pick 2 pairs is C*(C-1)/2.
    // Each pair of pairs can be arranged in 8 ways (a,b,c,d), (b,a,c,d)...
    // So total = sum(C*(C-1)/2 * 8) = sum(4*C*(C-1))
    
    long long result = 0;
    for (auto& p : prodCount) {
        long long c = p.second;
        result += 4 * c * (c - 1);
    }
    
    cout << result << endl;
    return 0;
}
