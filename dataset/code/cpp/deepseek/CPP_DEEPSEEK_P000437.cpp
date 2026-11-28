#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findFloor(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target)
            return arr[mid];
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target: ";
    int target;
    cin >> target;
    cout << "Floor value: " << findFloor(arr, n, target) << endl;
    return 0;
}