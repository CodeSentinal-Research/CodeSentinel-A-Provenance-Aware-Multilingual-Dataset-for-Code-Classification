Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            cout << mid << endl;
            break;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return 0;
}

This code first reads in the size of the array and the target value. It then reads in the array of integers. The binary search algorithm is then used to find the target in the array. If the target is found, the index is printed, otherwise, the algorithm continues to find the target in the array by halving the search space.