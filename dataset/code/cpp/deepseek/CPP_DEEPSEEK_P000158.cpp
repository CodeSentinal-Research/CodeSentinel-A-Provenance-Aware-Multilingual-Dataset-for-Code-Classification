#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_so_far = INT_MIN;
    int max_ending_here = 1;

    for(int i = 1; i < n; i++) {
        if (arr[i-1] < arr[i]) {
            max_ending_here++;
        } else {
            max_ending_here = 1;
        }
        if (max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
        }
    }

    cout << max_so_far;

    return 0;
}
This program reads an integer N followed by N integers. It then iterates through the array, incrementing a variable max_ending_here whenever it encounters a number that is greater than the previous one. If it encounters a number that is less than the previous one, it resets max_ending_here. The maximum sum of a subarray is updated whenever max_so_far is less than max_ending_here. At the end of the loop, max_so_far holds the maximum sum of a contiguous increasing subarray.