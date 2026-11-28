#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int partition(vector<int>& arr, int lo, int hi) {
        int pivot = arr[hi], i = lo-1;
        for (int j = lo; j < hi; j++)
            if (arr[j] <= pivot) swap(arr[++i], arr[j]);
        swap(arr[i+1], arr[hi]);
        return i+1;
    }
public:
    void quickSort(vector<int>& arr, int lo, int hi) {
        if (lo < hi) {
            int pi = partition(arr, lo, hi);
            quickSort(arr, lo, pi-1);
            quickSort(arr, pi+1, hi);
        }
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    Solution().quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i] << (i<n-1?" ":"\n");
}
