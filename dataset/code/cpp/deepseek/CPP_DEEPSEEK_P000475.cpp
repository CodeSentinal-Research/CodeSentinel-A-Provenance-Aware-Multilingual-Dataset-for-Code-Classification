Here is the C++ code that fulfills the requirements. It implements binary search to find the position of the target in an infinite sorted array.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int start = 0;
    int end = 1;
    
    while(arr[end] <= target) {
        int temp = end;
        end += (end - start);
        start = temp;
    }
    
    return binary_search(arr, start, end, target);
}

int main() {
    vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int target;
    
    cout << "Enter the target value: ";
    cin >> target;
    
    int pos = binarySearch(arr, target);
    
    if(pos != -1)
        cout << "Target found at position: " << pos << endl;
    else
        cout << "Target not found." << endl;
    
    return 0;
}

In this code, we use binary search to find the range of possible positions for the target value. We then use that range to perform a binary search on the actual array. If the target is found, we return its position, otherwise, we return -1 to indicate that the target was not found.

Please note that this code assumes that the input is a sorted array. If the input is an infinite sorted array, you would need a different approach to find the position of the target, as it would require a way to generate the array indefinitely.