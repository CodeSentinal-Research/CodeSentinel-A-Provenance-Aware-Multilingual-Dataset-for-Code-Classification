#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(int arr[], int n) {
    unordered_map<int, int> count;
    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    for(int i = 0; i < n; i++) {
        if (count[arr[i]] == 1)
            return arr[i];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << firstNonRepeating(arr, n);
    return 0;
}