Here is a simple C++ solution for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> pairs;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pairs.push_back(make_pair(a[i] + b[j], make_pair(a[i], b[j])));
        }
    }

    sort(pairs.begin(), pairs.end(), greater<pair<int, pair<int, int>>>());

    for (int i = 0; i < K && i < pairs.size(); i++) {
        cout << pairs[i].second.first << " " << pairs[i].second.second << endl;
    }

    return 0;
}
This code first takes the size of the two arrays and the number of pairs to find. It then takes the two arrays as input. It then creates a vector of pairs where each pair consists of the sum of two elements from the two arrays and the two elements themselves. The vector of pairs is then sorted in descending order according to the sum of the pair. Finally, it prints the K largest pair sums.