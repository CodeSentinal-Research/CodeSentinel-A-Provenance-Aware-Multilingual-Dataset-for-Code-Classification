Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum3(int k, int n, int start, vector<int> &candidates, vector<vector<int>> &results) {
    if (k == 0 && n == 0) {
        results.push_back(candidates);
        return;
    }
    if (k == 0 || n == 0 || start > 9) {
        return;
    }
    candidates.push_back(start);
    combinationSum3(k - 1, n - start, start + 1, candidates, results);
    candidates.pop_back();
    combinationSum3(k, n, start + 1, candidates, results);
}

int main() {
    int k, n;
    vector<vector<int>> results;

    cin >> k >> n;

    combinationSum3(k, n, 1, vector<int>(), results);

    for (auto &result : results) {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
This code uses a recursive approach to generate all combinations of numbers from 1 to 9. It uses a vector to keep track of the current combination and a vector of vectors to store all the valid combinations.