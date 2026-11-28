#include <iostream>
#include <vector>

using namespace std;

int countStrictlyIncreasingWindows(vector<int>& arr, int K) {
    int count = 0;
    for (int i = 0; i < arr.size() - K + 1; i++) {
        if (arr[i + K - 1] > arr[i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << countStrictlyIncreasingWindows(arr, K) << endl;
    return 0;
}