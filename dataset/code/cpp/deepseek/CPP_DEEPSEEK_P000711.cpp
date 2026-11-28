Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateCombinations(int n, int k, vector<int> &current, vector<vector<int>> &result) {
    if (current.size() == k) {
        result.push_back(current);
        return;
    }

    for (int i = n; i >= 1; i--) {
        current.push_back(i);
        generateCombinations(i - 1, k, current, result);
        current.pop_back();
    }
}

int main() {
    int n, k;
    cout << "Enter N and K: ";
    cin >> n >> k;

    vector<vector<int>> result;
    vector<int> current;
    generateCombinations(n, k, current, result);

    for (const auto &comb : result) {
        for (int num : comb) {
            cout << num << ' ';
        }
        cout << '\n';
    }

    return 0;
}
This program first reads the input values for N and K. It then calls a recursive function to generate all combinations. The recursive function uses a vector to keep track of the current combination and a vector of vectors to store all the combinations. The base case is when the size of the current combination equals K, in which case the current combination is added to the result and the function returns. Otherwise, for each number from N to 1, it adds the number to the current combination, calls the recursive function on the decremented number, and then removes the number from the current combination before returning.