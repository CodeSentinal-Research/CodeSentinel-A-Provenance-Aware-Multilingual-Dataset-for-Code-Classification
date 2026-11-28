#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<int>& maxH) {
    int n = maxH.size();
    long long res = 0;
    for (int i = 0; i < n; i++) {
        long long sum = maxH[i], curr = maxH[i];
        for (int j = i - 1; j >= 0; j--) { curr = min((long long)maxH[j], curr); sum += curr; }
        curr = maxH[i];
        for (int j = i + 1; j < n; j++) { curr = min((long long)maxH[j], curr); sum += curr; }
        res = max(res, sum);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> maxH(n);
    for(int i = 0; i < n; i++) cin >> maxH[i];
    cout << solve(maxH) << endl;
    return 0;
}
