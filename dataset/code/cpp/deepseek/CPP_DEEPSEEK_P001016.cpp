#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq; 

    for(int i = 0; i < N; i++) {
        pq.push(arr[i]);
        if(pq.size() > K) {
            pq.pop();
        }
        if(i >= K-1) {
            cout << pq.top() << " ";
            if(i != N-1) {
                cout << " ";
            }
            pq.pop();
        }
    }
    cout << endl;

    return 0;
}
This C++ code uses a priority queue to find the maximum element in each subarray of size K. The priority queue is a heap data structure that can efficiently return the maximum element. The maximum element is always at the top of the heap. If the size of the queue exceeds K, the maximum element in the window is popped out. The pop out operation is done in a controlled way to prevent unnecessary elements from being popped out. The output is done properly with a space between each number.