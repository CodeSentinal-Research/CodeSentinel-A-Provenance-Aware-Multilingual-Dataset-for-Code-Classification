#include <iostream>
#include <algorithm>

using namespace std;

long long maxTime(int n, int m, int* batteries) {
    long long totalBatteryTime = 0;
    for (int i = 0; i < m; i++) {
        totalBatteryTime += batteries[i];
    }

    long long maxRunningTime = totalBatteryTime / n;

    if (totalBatteryTime < n) {
        maxRunningTime = 0;
    }

    return maxRunningTime;
}

int main() {
    int n;
    int m;
    cin >> n >> m;

    int* batteries = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> batteries[i];
    }

    cout << maxTime(n, m, batteries);

    delete[] batteries;

    return 0;
}