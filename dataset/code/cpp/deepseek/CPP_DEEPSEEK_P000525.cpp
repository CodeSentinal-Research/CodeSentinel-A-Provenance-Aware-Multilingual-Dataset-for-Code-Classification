#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxHeights[n];
    for(int i = 0; i < n; i++) {
        cin >> maxHeights[i];
    }

    sort(maxHeights, maxHeights+n, greater<int>());

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (long long)maxHeights[i] * (i + 1);
    }

    cout << sum << endl;

    return 0;
}
In this code, we first take the number of towers as input. Then, we take the maximum height of each tower as input. We sort the heights in descending order. After sorting, we calculate the sum of each tower's height multiplied by its position (starting from 1). The result is the maximum possible sum of all tower heights.