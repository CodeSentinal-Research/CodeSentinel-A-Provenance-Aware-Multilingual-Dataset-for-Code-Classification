#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void selectionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++)
                if (arr[j] < arr[minIdx]) minIdx = j;
            swap(arr[i], arr[minIdx]);
        }
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    Solution().selectionSort(arr);
    for (int i = 0; i < n; i++) cout << arr[i] << (i<n-1?" ":"\n");
}
