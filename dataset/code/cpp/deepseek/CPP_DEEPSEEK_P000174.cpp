#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;
    for(int i = 0; i < N - 1; i++) {
        if(abs(arr[i] - arr[i+1]) < min_diff) {
            min_diff = abs(arr[i] - arr[i+1]);
        }
    }

    cout << min_diff << endl;

    return 0;
}