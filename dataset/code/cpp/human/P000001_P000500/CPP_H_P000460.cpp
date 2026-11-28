#include <iostream>
#include <vector>
using namespace std;

// Step 1: Find the peak element (bitonic point)
int findPeak(const vector<int>& nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1; // peak is to the right
        } else {
            right = mid;    // peak is at mid or to the left
        }
    }

    return left;
}

// Binary search on increasing subarray
int binarySearchInc(const vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

// Binary search on decreasing subarray
int binarySearchDec(const vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

// Main function to search in bitonic array
int searchBitonic(const vector<int>& nums, int target) {
    int peak = findPeak(nums);

    // Try the increasing part
    int index = binarySearchInc(nums, 0, peak, target);
    if (index != -1) return index;

    // Try the decreasing part
    return binarySearchDec(nums, peak + 1, nums.size() - 1, target);
}

int main() {
    vector<int> A = {1, 3, 8, 12, 4, 2};
    int B = 4;

    int result = searchBitonic(A, B);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the bitonic array." << endl;

    return 0;
}