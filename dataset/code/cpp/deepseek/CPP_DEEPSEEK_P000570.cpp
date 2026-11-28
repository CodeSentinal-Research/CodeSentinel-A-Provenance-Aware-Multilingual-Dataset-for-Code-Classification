#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    K = K % N; 

    queue<int> q;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        q.push(num);
    }

    queue<int> result;
    for(int i = 0; i < N; i++) {
        int num = q.front();
        q.pop();
        if(i < K) {
            result.push(num);
        } else {
            q.push(num);
        }
    }

    while(!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}
This program reads the size of the queue and the rotation value from the standard input, and then processes the queue based on the rotation value. The queue is rotated left by K positions, and then the rotated queue is printed to the standard output.