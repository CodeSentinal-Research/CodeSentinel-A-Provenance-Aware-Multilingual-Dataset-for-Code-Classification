#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> map;
    int sum = 0, maxLen = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];

        if (sum == K) {
            maxLen = i + 1;
        } else if (map.find(sum - K) != map.end()) {
            if (maxLen < i - map[sum - K]) {
                maxLen = i - map[sum - K];
            }
        }

        if (map.find(sum) == map.end()) {
            map[sum] = i;
        }
    }

    cout << (maxLen == 0 ? -1 : maxLen) << endl;

    return 0;
}