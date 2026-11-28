#include <iostream>
#include <vector>
using namespace std;
class Solution {
    void merge(vector<int>& arr, int l, int m, int r) {
        vector<int> L(arr.begin()+l, arr.begin()+m+1);
        vector<int> R(arr.begin()+m+1, arr.begin()+r+1);
        int i=0, j=0, k=l;
        while (i<(int)L.size() && j<(int)R.size())
            arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
        while (i<(int)L.size()) arr[k++]=L[i++];
        while (j<(int)R.size()) arr[k++]=R[j++];
    }
public:
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = l+(r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
};
int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto& x : arr) cin >> x;
    Solution().mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++) cout << arr[i] << (i<n-1?" ":"\n");
}
