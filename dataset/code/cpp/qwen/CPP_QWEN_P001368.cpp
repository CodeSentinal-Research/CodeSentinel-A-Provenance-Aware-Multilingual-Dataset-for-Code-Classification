#include <iostream>
#include <vector>
using namespace std;

int countVowelStrings(int n) {
    vector<int> dp(5, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < 5; ++j) {
            dp[j] += dp[j-1];
        }
    }
    int sum = 0;
    for (int x : dp) sum += x;
    return sum;
}

int main() {
    int n;
    cin >> n;
    cout << countVowelStrings(n) << endl;
    return 0;
}
