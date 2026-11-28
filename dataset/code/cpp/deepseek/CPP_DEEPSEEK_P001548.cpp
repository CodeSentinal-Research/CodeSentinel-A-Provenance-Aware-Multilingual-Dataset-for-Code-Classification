#include <iostream>
#include <deque>
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
    vector<long long> maxProduct(N, 1);
    for (int i = 0; i < N; i++) {
        while (!dq.empty() && dq.front() == i - K) {
            dq.pop_front();
        }
        dq.push_back(i);
        if (i >= K - 1) {
            maxProduct[i] *= arr[dq.front()];
        }
        if (i >= K) {
            maxProduct[i] *= maxProduct[i - K];
        }
    }
    
    long long maxProductWindow = maxProduct[0];
    for (long long p : maxProduct) {
        maxProductWindow = max(maxProductWindow, p);
    }
    
    cout << maxProductWindow;
    
    return 0;
}