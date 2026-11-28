#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    sort(stones.begin(), stones.end());

    int minEnergy = stones[N-1] - stones[0];
    for (int i = 1; i < N; i++) {
        minEnergy = min(minEnergy, stones[i] - stones[i-1]);
    }

    int minJumps = K + 1;
    for (int i = 0; i < N-1; i++) {
        int j = upper_bound(stones.begin()+i+1, stones.end(), stones[i] + minEnergy) - stones.begin();
        minJumps = min(minJumps, j - (i - (j-1) % K * (j-1) % K / 2));
    }

    cout << minJumps * minEnergy << "\n";

    return 0;
}