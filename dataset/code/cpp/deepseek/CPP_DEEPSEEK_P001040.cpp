#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> speeds(N);
    vector<int> efficiencies(N);

    for (int i = 0; i < N; i++) {
        cin >> speeds[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> efficiencies[i];
    }

    vector<int> selected_speeds;
    vector<int> selected_efficiencies;

    for (int i = 0; i < N; i++) {
        int min_efficiency = efficiencies[i];
        for (int j = i; j < N; j++) {
            min_efficiency = min(min_efficiency, efficiencies[j]);
        }
        for (int j = 0; j < K; j++) {
            selected_speeds.push_back(speeds[i]);
            selected_efficiencies.push_back(min_efficiency);
        }
    }

    int performance = 0;
    for (int i = 0; i < N; i++) {
        performance += selected_speeds[i] * selected_efficiencies[i];
    }

    cout << performance << endl;

    return 0;
}