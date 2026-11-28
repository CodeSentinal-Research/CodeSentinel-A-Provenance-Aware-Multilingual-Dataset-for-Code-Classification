#include <iostream>
#include <vector>
using namespace std;

void generateCombinations(int n, int k, int start, vector<int>& current) {
    if (k == 0) {
        for (size_t i = 0; i < current.size(); ++i) {
            if (i > 0) cout << " ";
            cout << current[i];
        }
        cout << endl;
        return;
    }
    for (int i = start; i <= n; ++i) {
        current.push_back(i);
        generateCombinations(n, k - 1, i + 1, current);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> current;
    generateCombinations(n, k, 1, current);
    return 0;
}
