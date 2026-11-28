#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int N, K, X;
    cin >> N >> K >> X;
    
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int count = 0;
    for (int i = 0; i < N - K + 1; i++) {
        int sum = 0;
        for (int j = i; j < i + K; j++) {
            sum += arr[j];
        }
        if (sum > X) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}