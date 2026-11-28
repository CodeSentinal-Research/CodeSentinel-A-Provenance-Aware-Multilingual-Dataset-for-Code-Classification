#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }
    sort(stones.begin(), stones.end());
    int energy = 0;
    for (int i = 0; i < N - 1; i++) {
        energy += abs(stones[i + 1] - stones[i]);
    }
    cout << energy;
    return 0;
}