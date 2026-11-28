#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    for (int i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1));
            for (int l : left) {
                for (int r : right) {
                    if (c == '+') result.push_back(l + r);
                    else if (c == '-') result.push_back(l - r);
                    else if (c == '*') result.push_back(l * r);
                }
            }
        }
    }
    if (result.empty()) result.push_back(stoi(input));
    return result;
}

int main() {
    string expr;
    cin >> expr;
    vector<int> res = diffWaysToCompute(expr);
    sort(res.begin(), res.end());
    for (int val : res) {
        cout << val << endl;
    }
    return 0;
}
