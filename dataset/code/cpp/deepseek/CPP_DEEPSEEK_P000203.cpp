#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int& num : arr) {
        cin >> num;
    }

    unordered_map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }

    int maxCount = 0;
    int maxRepeatingNum = 0;
    for (auto& pair : freq) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxRepeatingNum = pair.first;
        }
    }

    cout << maxRepeatingNum;

    return 0;
}