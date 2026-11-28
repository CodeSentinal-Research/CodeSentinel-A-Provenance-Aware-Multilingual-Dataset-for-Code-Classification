#include <iostream>
using namespace std;

int findTransitionPoint(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int result = findTransitionPoint(arr, n);
    if(result == -1) {
        cout << "No 1 exists" << endl;
    } else {
        cout << "First 1 is at index: " << result << endl;
    }
    return 0;
}