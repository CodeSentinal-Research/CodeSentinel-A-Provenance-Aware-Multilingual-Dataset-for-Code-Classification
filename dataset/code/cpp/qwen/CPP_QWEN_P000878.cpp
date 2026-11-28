#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    set<int> orValues;
    set<int> prevOrs;
    
    for (int num : nums) {
        set<int> currentOrs;
        currentOrs.insert(num);
        for (int p : prevOrs) {
            currentOrs.insert(p | num);
        }
        for (int c : currentOrs) {
            orValues.insert(c);
        }
        prevOrs = currentOrs;
    }
    
    cout << orValues.size() << endl;
    return 0;
}
