#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long totalDistance = 0;
    for (int bit = 0; bit < 32; ++bit) {
        int countSet = 0;
        for (int num : nums) {
            if (num & (1 << bit)) countSet++;
        }
        int countUnset = n - countSet;
        totalDistance += (long long)countSet * countUnset;
    }
    cout << totalDistance << endl;
    return 0;
}
