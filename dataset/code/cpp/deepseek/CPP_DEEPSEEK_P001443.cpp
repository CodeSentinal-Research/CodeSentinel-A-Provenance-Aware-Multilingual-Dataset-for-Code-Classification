#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool is_obtainable(const string& w1, const string& w2) {
    if (w1.size() != w2.size() + 1) return false;
    int i1 = 0, i2 = 0;
    while (i1 < w1.size() && i2 < w2.size()) {
        if (w1[i1] == w2[i2]) {
            i1++;
            i2++;
        } else {
            i1++;
        }
    }
    return i2 == w2.size();
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> words1(N);
    for (int i = 0; i < N; i++) {
        cin >> words1[i];
    }
    vector<string> words2(M);
    for (int i = 0; i < M; i++) {
        cin >> words2[i];
    }
    unordered_set<string> sets;
    for (const auto& w1 : words1) {
        for (const auto& w2 : words2) {
            if (is_obtainable(w1, w2)) {
                sets.insert(w1);
            }
        }
    }
    cout << sets.size() << "\n";
    return 0;
}