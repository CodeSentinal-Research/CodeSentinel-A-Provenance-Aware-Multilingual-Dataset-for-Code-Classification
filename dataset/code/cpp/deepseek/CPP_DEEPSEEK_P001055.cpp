#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int d, f, n, a;
    cin >> d >> f >> n;

    vector<int> stations(n+2);
    for (int i = 0; i < n+1; ++i) {
        cin >> a;
        stations[i] = a;
    }

    stations[n+1] = d;

    vector<int> dp(d+2, -1);
    dp[0] = 0;

    for (int i = 0; i < n+1; ++i) {
        for (int j = stations[i]; j >= 0; --j) {
            if (dp[j] != -1 && dp[j] + 1 >= dp[stations[i]+1]) {
                dp[stations[i]+1] = dp[j] + 1;
            }
        }
    }

    int stops = 0;
    for (int i = 0; i <= d; ++i) {
        if (dp[i] != -1 && dp[i] <= f) {
            ++stops;
            f -= dp[i];
        } else {
            break;
        }
    }

    if (stops == 0 && f > 0) {
        cout << -1 << endl;
    } else {
        cout << stops << endl;
    }

    return 0;
}