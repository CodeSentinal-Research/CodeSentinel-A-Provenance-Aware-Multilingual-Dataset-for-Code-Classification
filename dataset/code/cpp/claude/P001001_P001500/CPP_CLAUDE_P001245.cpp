#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long solve(vector<int>& arr) {
        long long sum = 0;
        for (int x : arr) sum += x;
        return sum;
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    cout << Solution().solve(arr) << "\n";
}
