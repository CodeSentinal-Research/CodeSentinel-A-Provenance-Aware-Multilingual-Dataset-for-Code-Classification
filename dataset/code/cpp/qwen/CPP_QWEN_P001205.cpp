#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    vector<int> length(n, 1);
    vector<int> count(n, 1);
    
    int maxLen = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                } else if (length[j] + 1 == length[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxLen = max(maxLen, length[i]);
    }
    
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        if (length[i] == maxLen) {
            total += count[i];
        }
    }
    
    cout << total << endl;
    return 0;
}
