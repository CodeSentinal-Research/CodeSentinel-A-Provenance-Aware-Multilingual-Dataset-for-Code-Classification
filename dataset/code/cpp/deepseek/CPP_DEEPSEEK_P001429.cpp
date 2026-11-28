#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    int ans = 0;
    for (auto& p : cnt) {
        for (auto& q : cnt) {
            if (p.first == q.first) continue;
            if (p.first * q.first == 1) ans += p.second * q.second;
        }
    }

    cout << ans << endl;
    return 0;
}