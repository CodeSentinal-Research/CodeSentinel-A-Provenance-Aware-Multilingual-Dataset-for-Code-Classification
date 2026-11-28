#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long totalPairs = (long long)n * (n - 1) / 2;
    long long goodPairs = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (j - i == nums[j] - nums[i]) {
                goodPairs++;
            }
        }
    }
    
    cout << totalPairs - goodPairs << endl;
    return 0;
}
