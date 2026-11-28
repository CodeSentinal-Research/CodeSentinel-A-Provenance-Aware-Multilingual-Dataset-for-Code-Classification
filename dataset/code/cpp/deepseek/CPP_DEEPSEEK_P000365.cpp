#include <iostream>
using namespace std;

int findMinIndex(int arr[], int n) {
    int minIndex = 0;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minIndex = findMinIndex(arr, n);
    cout << minIndex;
    return 0;
}