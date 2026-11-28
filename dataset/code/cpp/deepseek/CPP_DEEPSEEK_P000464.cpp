#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int target;

    cin >> N >> target;

    vector<int> arr(N);

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int closest = *lower_bound(arr.begin(), arr.end(), target);

    cout << closest << endl;

    return 0;
}