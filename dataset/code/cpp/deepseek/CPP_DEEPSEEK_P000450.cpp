#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int missing = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i] != i + 1) {
            missing++;
        }
        if(missing == K) {
            cout << arr[i] + K - missing;
            return 0;
        }
    }
    cout << "No Kth missing positive number found";
    return 0;
}