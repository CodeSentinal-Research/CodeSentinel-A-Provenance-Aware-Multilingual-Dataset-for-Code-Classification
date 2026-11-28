#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        int lo = 0, hi = arr.size()-1;
        while (lo <= hi) {
            int mid = lo + (hi-lo)/2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
        return -1;
    }
};
int main() {
    int n, target; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    cin >> target;
    int idx = Solution().binarySearch(arr, target);
    if (idx == -1) cout << "Not Found\n";
    else cout << idx << "\n";
}
