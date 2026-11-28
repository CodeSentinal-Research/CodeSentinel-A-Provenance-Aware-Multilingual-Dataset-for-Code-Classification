#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canFormSquare(vector<int>& matchsticks, int index, vector<long long>& sides, long long target) {
    if (index == matchsticks.size()) {
        return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
    }
    
    for (int i = 0; i < 4; ++i) {
        if (sides[i] + matchsticks[index] <= target) {
            sides[i] += matchsticks[index];
            if (canFormSquare(matchsticks, index + 1, sides, target)) return true;
            sides[i] -= matchsticks[index];
        }
        if (sides[i] == 0) break;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> matchsticks(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> matchsticks[i];
        sum += matchsticks[i];
    }
    
    if (sum % 4 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    long long target = sum / 4;
    vector<long long> sides(4, 0);
    sort(matchsticks.rbegin(), matchsticks.rend());
    
    cout << (canFormSquare(matchsticks, 0, sides, target) ? "YES" : "NO") << endl;
    return 0;
}
