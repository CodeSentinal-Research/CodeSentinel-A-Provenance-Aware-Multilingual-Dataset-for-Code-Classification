#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);
    for (int i = 0; i < n; i++) {
        cin >> arrival[i] >> departure[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platform = 1, i = 1, j = 0;
    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platform++;
            i++;
        } else {
            platform--;
            j++;
        }
    }

    cout << platform;

    return 0;
}