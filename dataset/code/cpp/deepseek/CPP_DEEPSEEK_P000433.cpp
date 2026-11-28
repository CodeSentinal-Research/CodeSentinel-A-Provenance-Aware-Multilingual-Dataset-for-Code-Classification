Here is the C++ solution for the given problem:

#include <iostream>
#include <vector>
using namespace std;

int findFirstOccurrence(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            end = mid - 1; 
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    if (start >= arr.size() || arr[start] != target) {
        return -1;
    }
    return start;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << findFirstOccurrence(arr, target);
    return 0;
}

This program works by using binary search to find the first occurrence of the target in the sorted array. The program first initializes two pointers, start and end, to the start and end of the array, respectively. Then it enters a loop where it computes the middle index and compares it to the target. If the middle element is the target, it updates the end to mid - 1 and continues the search on the left part. If the middle element is less than the target, it updates the start to mid + 1 and continues the search on the right part. If the middle element is greater than the target, it updates the end to mid - 1 and continues the search on the left part. If after the loop it doesn't find the target, it returns -1.