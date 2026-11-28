#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main() {
    int N, K, initialCapital;
    cin >> N >> K >> initialCapital;
    vector<pair<int, int>> projects(N);
    for (int i = 0; i < N; i++) {
        int capital, profit;
        cin >> capital >> profit;
        projects[i] = make_pair(capital, profit);
    }
    sort(projects.begin(), projects.end(), comp);
    int maxProfit = 0;
    for (int i = 0; i < N && K > 0; i++) {
        if (initialCapital >= projects[i].first) {
            initialCapital += projects[i].second;
            maxProfit = max(maxProfit, initialCapital);
            K--;
        }
    }
    cout << maxProfit << endl;
    return 0;
}