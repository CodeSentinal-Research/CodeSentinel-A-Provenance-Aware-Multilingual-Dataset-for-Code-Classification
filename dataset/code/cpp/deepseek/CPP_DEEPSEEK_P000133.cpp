Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> res(n);
    int i = 0, j = n - 1, k = 0;
    while(i < j) {
        res[k++] = arr[j--];
        if(i != j) {
            res[k++] = arr[i++];
        }
    }
    if(i == j) {
        res[k++] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    return 0;
}

In this code, we are first reading the size of the array and the elements of the array. We then sort the array in ascending order. We create a new array `res` to store the rearranged array. We start with the maximum element from the end of the sorted array and the minimum element from the beginning of the sorted array and add them to `res` in alternating order. If the size of the array is odd, the middle element is added as it is. Finally, we print the rearranged array.