#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int inversions = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << countInversions(arr, n) << endl;
    return 0;
}