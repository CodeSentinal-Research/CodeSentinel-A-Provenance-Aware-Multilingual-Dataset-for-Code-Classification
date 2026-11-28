#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    set<int> uniqueVals;
    for (int num : nums) {
        if (num > 0) uniqueVals.insert(num);
    }
    
    cout << uniqueVals.size() << endl;
    return 0;
}
