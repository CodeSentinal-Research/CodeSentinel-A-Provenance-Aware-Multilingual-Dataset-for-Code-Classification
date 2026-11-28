#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<int>& maxH) {
    int n = maxH.size();
    vector<long long> left(n), right(n);
    left[0] = maxH[0];
    for (int i = 1; i < n; i++) left[i] = min((long long)maxH[i], left[i-1]);
    right[n-1] = maxH[n-1];
    for (int i = n - 2; i >= 0; i--) right[i] = min((long long)maxH[i], right[i+1]);
    long long res = 0;
    for (int i = 0; i < n; i++) res += min(left[i], right[i]);
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> maxH(n);
    for(int i = 0; i < n; i++) cin >> maxH[i];
    cout << solve(maxH) << endl;
    return 0;
}
