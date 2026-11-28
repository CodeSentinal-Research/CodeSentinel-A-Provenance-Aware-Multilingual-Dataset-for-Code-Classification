#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int,int> a, pair<int,int> b) {
    return a.first > b.first;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> speeds(N);
    vector<pair<int,int>> efficiencies(N);

    for(int i = 0; i < N; i++) {
        cin >> speeds[i].first >> efficiencies[i].first;
        speeds[i].second = efficiencies[i].second = i;
    }

    sort(speeds.begin(), speeds[N], comp);
    sort(efficiencies.begin(), efficiencies[N], comp);

    int max_speed = speeds[0].first;
    int min_eff = efficiencies[0].first;

    for(int i = 0; i < N; i++) {
        if(speeds[i].first == max_speed && efficiencies[i].first == min_eff) {
            cout << max_speed << ' ' << min_eff;
            return 0;
        }
    }
}