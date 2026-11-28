#include <iostream>
#include <vector>

using namespace std;

pair<pair<int, int>, pair<int, int>> findFirstAndLastOccurrence(vector<int> nums, int target) {
    pair<int, int> firstOccurrence = make_pair(-1, -1);
    pair<int, int> lastOccurrence = make_pair(-1, -1);
    
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            end = mid - 1;
            lastOccurrence.first = mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    start = 0;
    end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) {
            start = mid + 1;
            firstOccurrence.second = mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return make_pair(firstOccurrence, lastOccurrence);
}

int main() {
    vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 9};
    int target = 3;
    pair<pair<int, int>, pair<int, int>> result = findFirstAndLastOccurrence(nums, target);
    
    cout << "First occurrence index: " << result.first.first << endl;
    cout << "Last occurrence index: " << result.second.second << endl;
    
    return 0;
}