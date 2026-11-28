#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<long long, int> prefixes;
    long long xorSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        xorSum ^= nums[i];
        if (prefixes.find(xorSum) != prefixes.end()) {
            count += prefixes[xorSum];
        }
        prefixes[xorSum]++;
    }

    cout << count << endl;

    return 0;
}