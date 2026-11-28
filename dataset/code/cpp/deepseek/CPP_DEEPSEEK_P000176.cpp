Here is the C++ code for the Chocolate Distribution Problem:

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findMinDifference(vector<int>& arr, int n, int k) {
    sort(arr.begin(), arr.end());
    
    int minDiff = arr[n-1] - arr[k-1];
    
    return minDiff;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << findMinDifference(arr, n, k);
    
    return 0;
}

This code first sorts the packet sizes in increasing order. It then calculates the difference between the last and first packet (which are the maximum and minimum of K packets). The function `findMinDifference` returns the minimum difference. In the `main` function, the program reads the number of packets and the array of packet sizes, and then prints the minimum difference.