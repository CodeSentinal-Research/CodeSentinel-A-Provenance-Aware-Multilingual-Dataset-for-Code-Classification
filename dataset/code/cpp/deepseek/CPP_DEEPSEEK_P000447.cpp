Here is the complete C++ code that will solve the problem:

#include <iostream>
#include <vector>
using namespace std;

void findPositions(vector<int>& arr, int target) {
    int firstOccurrence = -1, lastOccurrence = -1;
    int start = 0, end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            end = mid - 1; 
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    start = 0; end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            lastOccurrence = mid;
            start = mid + 1; 
        } else if (arr[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (firstOccurrence != -1 && lastOccurrence != -1) {
        cout << firstOccurrence << " " << lastOccurrence;
    } else {
        cout << "-1 -1";
    }
}

int main() {
    int N, target;
    cin >> N >> target;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    findPositions(arr, target);

    return 0;
}
This code works by using binary search to find the first and last occurrence of the target in the array. It uses two pointers (start and end) to perform binary search. The midpoint of the search space is calculated using the formula (start + (end - start) / 2). If the midpoint is the target, the start pointer is moved to the right, and the end pointer is moved to the left. If the target is greater than the midpoint, the start pointer is moved to the right. If the target is less than the midpoint, the end pointer is moved to the left. This process is repeated until the target is found or the search space is exhausted.