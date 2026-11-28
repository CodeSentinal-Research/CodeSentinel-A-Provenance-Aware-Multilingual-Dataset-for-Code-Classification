#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    unordered_map<int, int> freqA;
    for (int& num : a) {
        cin >> num;
        freqA[num]++;
    }

    vector<int> b(M);
    unordered_map<int, int> freqB;
    for (int& num : b) {
        cin >> num;
        freqB[num]++;
    }

    if (a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }

    for (int num : a) {
        if (freqA[num] != freqB[num]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}