#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i], j = i-1;
            while (j >= 0 && arr[j] > key) { arr[j+1] = arr[j]; j--; }
            arr[j+1] = key;
        }
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    Solution().insertionSort(arr);
    for (int i = 0; i < n; i++) cout << arr[i] << (i<n-1?" ":"\n");
}
