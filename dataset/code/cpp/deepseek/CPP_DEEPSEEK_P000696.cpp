#include <iostream>
using namespace std;

int lastOccurrence(int nums[], int start, int end, int target) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
        if (mid == end) {
            return mid;
        } else if (nums[mid + 1] != target) {
            return mid;
        } else {
            return lastOccurrence(nums, mid + 1, end, target);
        }
    } else if (nums[mid] > target) {
        return lastOccurrence(nums, start, mid - 1, target);
    } else {
        return lastOccurrence(nums, mid + 1, end, target);
    }
}

int main() {
    int nums[] = {2, 4, 10, 10, 10, 18, 20};
    int target = 10;
    int start = 0;
    int end = sizeof(nums) / sizeof(nums[0]) - 1;
    cout << lastOccurrence(nums, start, end, target);
    return 0;
}