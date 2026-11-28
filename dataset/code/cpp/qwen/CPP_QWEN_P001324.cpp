#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
    if (k == 0 && n == 0) {
        result.push_back(current);
        return;
    }
    if (k == 0 || n <= 0) return;
    
    for (int i = start; i <= 9; ++i) {
        current.push_back(i);
        findCombinations(k - 1, n - i, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(k, n, 1, current, result);
    
    for (const auto& comb : result) {
        for (size_t i = 0; i < comb.size(); ++i) {
            if (i > 0) cout << " ";
            cout << comb[i];
        }
        cout << endl;
    }
    return 0;
}
