#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChunksToSorted(vector<int> arr) {
    int n = arr.size();
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());
    int chunks = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == sorted[i]) {
            chunks++;
        }
    }
    return chunks;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << maxChunksToSorted(arr) << "\n";
    return 0;
}