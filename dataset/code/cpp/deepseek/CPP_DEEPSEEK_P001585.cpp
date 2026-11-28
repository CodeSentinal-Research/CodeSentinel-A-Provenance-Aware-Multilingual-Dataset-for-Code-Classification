#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    for(int i = 1; i < N; i++) {
        if(arr[i] == arr[i - 1]) {
            ans++;
        }
    }
    cout << max(ans, arr[0]) << endl;
}

int main() {
    solve();
    return 0;
}