#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    map<int,int> frequency(vector<int>& arr) {
        map<int,int> freq;
        for (int x : arr) freq[x]++;
        return freq;
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    auto f = Solution().frequency(arr);
    for (auto& [k,v] : f) cout << k << ": " << v << "\n";
}
