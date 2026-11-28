#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < K; i++) {
        int num;
        cin >> num;
        minHeap.push(num);
    }
    
    for (int i = K; i < N; i++) {
        int num;
        cin >> num;
        
        if (num < minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
    }
    
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    
    return 0;
}