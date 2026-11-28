#include <iostream>
#include <vector>
using namespace std;

long long mergeAndCount(vector<int>& nums, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = nums[l + i];
    for (int j = 0; j < n2; ++j) R[j] = nums[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    long long invCount = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k++] = L[i++];
        } else {
            nums[k++] = R[j++];
            invCount += (n1 - i);
        }
    }
    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];
    return invCount;
}

long long mergeSortAndCount(vector<int>& nums, int l, int r) {
    long long invCount = 0;
    if (l < r) {
        int m = l + (r - l) / 2;
        invCount += mergeSortAndCount(nums, l, m);
        invCount += mergeSortAndCount(nums, m + 1, r);
        invCount += mergeAndCount(nums, l, m, r);
    }
    return invCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    cout << mergeSortAndCount(nums, 0, n - 1) << endl;
    return 0;
}
