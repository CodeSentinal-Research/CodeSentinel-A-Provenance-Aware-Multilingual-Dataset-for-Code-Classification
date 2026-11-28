Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> keypad = {
        " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    vector<string> combinations;
    if (digits.empty()) {
        return combinations;
    }

    string combination;
    dfs(digits, 0, combination, keypad, combinations);

    return combinations;
}

void dfs(string digits, int index, string combination, vector<string> &keypad, vector<string> &combinations) {
    if (index == digits.length()) {
        combinations.push_back(combination);
        return;
    }

    int number = digits[index] - '0';
    string letters = keypad[number];

    for (int i = 0; i < letters.length(); i++) {
        combination.push_back(letters[i]);
        dfs(digits, index + 1, combination, keypad, combinations);
        combination.pop_back();
    }
}

int main() {
    string digits;
    cin >> digits;

    vector<string> combinations = letterCombinations(digits);

    sort(combinations.begin(), combinations.end());

    for (int i = 0; i < combinations.size(); i++) {
        cout << combinations[i] << endl;
    }

    return 0;
}

This code first defines a 2D vector `keypad` where each entry corresponds to a number from 2 to 9 and the corresponding letters. The main function then calls `letterCombinations` to get all combinations. This function uses depth-first search (DFS) to explore all possible combinations.

The `dfs` function is a helper function that performs DFS on the digits string. It recursively generates all combinations of the given digits and adds them to the `combinations` vector.

Finally, the `main` function reads the digits input, calls `letterCombinations` to get all combinations, sorts them, and prints them.