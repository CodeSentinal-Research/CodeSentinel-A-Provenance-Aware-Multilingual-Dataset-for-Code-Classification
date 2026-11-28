#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> numbers;
vector<vector<int>> combinations;

void generateCombinations(int index, vector<int>& combination) {
    if (combination.size() == K) {
        combinations.push_back(combination);
        return;
    }

    for (int i = index; i <= N; i++) {
        combination.push_back(i);
        generateCombinations(i + 1, combination);
        combination.pop_back();
    }
}

int main() {
    cin >> N >> K;

    generateCombinations(1, vector<int>());

    sort(combinations.begin(), combinations.end());

    for (const auto& combination : combinations) {
        for (int number : combination) {
            cout << number << ' ';
        }
        cout << '\n';
    }

    return 0;
}