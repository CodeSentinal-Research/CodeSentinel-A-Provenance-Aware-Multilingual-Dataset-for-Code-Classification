#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);
    return i + 1;
}

void quickSortRecursive(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pi = partition(nums, low, high);
        quickSortRecursive(nums, low, pi - 1);
        quickSortRecursive(nums, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    quickSortRecursive(nums, 0, n - 1);
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    return 0;
}
