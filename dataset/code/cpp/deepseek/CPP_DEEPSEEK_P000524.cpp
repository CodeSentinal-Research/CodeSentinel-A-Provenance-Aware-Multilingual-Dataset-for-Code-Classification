#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxHeights[n];
    for (int i = 0; i < n; i++) {
        cin >> maxHeights[i];
    }

    sort(maxHeights, maxHeights + n, greater<int>());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += maxHeights[i];
    }

    cout << sum << endl;

    return 0;
}