#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    deque<int> dq;
    for (int i = 0; i < K; i++) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    cout << arr[dq.front()] << endl;
    
    for (int i = K; i < N; i++) {
        if (dq.front() == i - K) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (arr[i] > arr[dq.front()]) {
            cout << arr[dq.front()] << endl;
        }
    }
    
    return 0;
}