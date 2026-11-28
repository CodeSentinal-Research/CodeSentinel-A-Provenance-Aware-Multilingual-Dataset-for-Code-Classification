#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;

    vector<int> jumps(n, INT_MAX);
    jumps[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }

    return jumps[n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minJumps(arr);
    return 0;
}
This C++ program uses a greedy approach with dynamic programming to solve the problem. It creates an array of size n (the size of the input array) and initializes all elements to INT_MAX (representing infinity). The array `jumps` stores the minimum number of jumps required to reach the end from the beginning of each index. 

For each index, it checks its neighbours and if the current index is reachable from the neighbour, it updates the minimum number of jumps required to reach the end for the current index. 

Finally, it returns the minimum number of jumps required to reach the end.