Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateSubsequences(string s, int index, string current, vector<string>& result) {
    if(index == s.length()) {
        result.push_back(current);
        return;
    }
    generateSubsequences(s, index + 1, current, result);
    current += s[index];
    generateSubsequences(s, index + 1, current, result);
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    generateSubsequences(s, 0, "", result);
    sort(result.begin(), result.end());
    for(string s : result) {
        cout << s << endl;
    }
    return 0;
}

This program uses recursion to generate all possible subsequences of a given string. The `generateSubsequences` function takes a string, the current index, the current subsequence, and a vector to store the result. If the current index is equal to the length of the string, the function adds the current subsequence to the result and returns. Otherwise, the function calls itself recursively to generate the subsequences without and with the current character.

In the main function, the user is prompted to enter a string. The function calls `generateSubsequences` with the initial string, index 0, an empty string, and an empty vector to store the result. The result is sorted lexicographically before being printed.