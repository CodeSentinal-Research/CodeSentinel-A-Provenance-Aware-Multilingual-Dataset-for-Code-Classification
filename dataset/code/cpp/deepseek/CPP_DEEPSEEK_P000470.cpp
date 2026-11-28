Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, target;
    cin >> N >> target;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int minDiff = abs(arr[0] - target);
    int minElement = arr[0];

    for (int i = 1; i < N; i++) {
        int diff = abs(arr[i] - target);
        if (diff < minDiff) {
            minDiff = diff;
            minElement = arr[i];
        }
    }

    cout << minElement << endl;

    return 0;
}
This program reads the size of the array and the target value, then reads the array of integers. It then calculates the absolute difference between each element and the target value, keeps track of the element with the smallest difference and the smallest difference found so far. Finally, it outputs the element with the smallest difference.