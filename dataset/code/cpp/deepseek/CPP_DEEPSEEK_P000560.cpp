#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    queue<int> q;
    for(int i=0; i<N; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    
    for(int i=0; i<N/2; i++) {
        int front = q.front();
        q.pop();
        q.push(front);
        
        int rear = q.back();
        q.pop();
        q.push(rear);
    }
    
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}

This C++ code uses a queue to solve the problem. It first reads the number of elements to be processed, and then for each element, it pushes the element into the queue. After that, it performs the interleaving operation by pushing the front element to the rear of the queue and popping the front element to the front of the queue for N/2 times. Finally, it prints out the interleaved queue.