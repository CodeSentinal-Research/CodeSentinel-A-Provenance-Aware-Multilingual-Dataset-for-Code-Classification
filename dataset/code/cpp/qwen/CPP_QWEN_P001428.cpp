#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> deliciousness(n);
    for (int i = 0; i < n; ++i) cin >> deliciousness[i];
    
    unordered_map<int, int> freq;
    long long count = 0;
    const int MOD = 1e9 + 7;
    
    for (int d : deliciousness) {
        // Check powers of 2 up to 2^21 (since max sum is 2*10^6 approx)
        for (int p = 1; p <= (1 << 21); p <<= 1) {
            int complement = p - d;
            if (freq.find(complement) != freq.end()) {
                count = (count + freq[complement]) % MOD;
            }
        }
        freq[d]++;
    }
    
    cout << count << endl;
    return 0;
}
