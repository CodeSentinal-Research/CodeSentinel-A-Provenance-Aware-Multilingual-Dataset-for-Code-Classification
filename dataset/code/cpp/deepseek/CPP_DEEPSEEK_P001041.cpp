Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> quality(N);
    vector<int> wage(N);
    for (int i = 0; i < N; i++) {
        cin >> quality[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> wage[i];
   
    }
    vector<pair<int, int>> workers;
    for (int i = 0; i < N; i++) {
        workers.push_back(make_pair(quality[i], wage[i]));
    }

    sort(workers.begin(), workers.end(), comp);

    int totalQuality = 0;
    for (int i = 0; i < K; i++) {
        totalQuality += workers[i].first;
    }

    cout << totalQuality << endl;

    return 0;
}

This code reads the number of workers and their qualities and wages. It then sorts the workers by quality in descending order. After sorting, it calculates the sum of the qualities of the first K workers, which are the workers with the highest quality.