Here is the complete C++ code for the problem:

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, limit;
    cin >> n >> limit;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int boats = 0;
    int i = 0;
    int j = n - 1;

    while (i <= j) {
        if (weights[i] + weights[j] <= limit) {
            boats++;
            i++;
            j--;
        } else {
            boats++;
            j--;
        }
    }

    cout << boats << endl;

    return 0;
}

In this code, we first read the number of people and the maximum weight each boat can carry, and then read the weights of the people. We then sort the weights in ascending order. We use two pointers, `i` and `j`, to traverse the weights from both ends. If the sum of the weights at the `i` and `j` index is less than or equal to the limit, we add a boat and increment both pointers. If the sum is more than the limit, we add a boat and decrement the pointer at `j`. We continue this until we reach the middle of the array.