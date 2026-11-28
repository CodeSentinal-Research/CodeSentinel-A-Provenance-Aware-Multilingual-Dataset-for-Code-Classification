#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int start = 0, end = 0;
    while (end < N) {
        int cnt = 0;
        while (end < N && arr[end] == arr[start] + cnt) {
            cnt++;
            end++;
        }
        if (cnt > 0) {
            if (end - start - cnt < K - 1) {
                cout << "NO";
                return 0;
            }
        }
        start = end - cnt;
    }
    cout << "YES";
    return 0;
}