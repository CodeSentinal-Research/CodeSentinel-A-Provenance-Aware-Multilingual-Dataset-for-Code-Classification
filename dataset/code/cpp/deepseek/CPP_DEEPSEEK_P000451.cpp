Sure, here is the C++ code that fulfills the given problem:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int target;
    cin >> target;

    vector<int> arr;
    int num;
    while(cin >> num) {
        arr.push_back(num);
    }

    int left = 0;
    int right = 1;

    while(arr[right] < target && right < arr.size()) {
        left = right;
        right *= 2;
    }

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target) {
            cout << mid << endl;
            return 0;
        }

        if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << -1 << endl;
    return 0;
}

This code first reads the target value from the standard input, then reads the array from the standard input. It then uses binary search to find the target value in the infinite sorted array. The code uses a while loop to keep expanding the search space until the target value is found. If the target value is not found, it outputs -1.