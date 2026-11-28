#include <iostream>
#include <unordered_set>
#include <deque>
#include <vector>

using namespace std;

void countDistinctInWindows(vector<int>& arr, int K) {
    unordered_set<int> distinctElements;

    for(int i = 0; i < arr.size(); i++) {
        distinctElements.insert(arr[i]);

        if(i >= K-1) {
            distinctElements.erase(arr[i-K]);
        }

        cout << distinctElements.size() << " ";
    }

    cout << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    countDistinctInWindows(arr, K);

    return 0;
}
This code uses a `deque` to store the elements of the current window and an `unordered_set` to store the distinct elements in the current window. The `unordered_set` automatically removes duplicates while maintaining the order of the elements. The size of the `unordered_set` is used to count the number of distinct elements in the current window.