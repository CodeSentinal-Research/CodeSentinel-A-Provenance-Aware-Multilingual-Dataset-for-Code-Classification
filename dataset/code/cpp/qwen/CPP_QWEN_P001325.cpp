#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
    if (k == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        generateCombinations(n, k - 1, i + 1, current, result);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> result;
    vector<int> current;
    generateCombinations(n, k, 1, current, result);
    
    for (const auto& comb : result) {
        for (size_t i = 0; i < comb.size(); ++i) {
            if (i > 0) cout << " ";
            cout << comb[i];
        }
        cout << endl;
    }
    return 0;
}
