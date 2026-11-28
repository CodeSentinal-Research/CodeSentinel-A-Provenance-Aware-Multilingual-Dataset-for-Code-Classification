Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

vector<int> addParentheses(string expression) {
    map<string, int> m;
    vector<int> results;
    if(m.find(expression) != m.end()) {
        return {m[expression]};
    }
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            string left = expression.substr(0, i);
            string right = expression.substr(i+1);
            string op = string(1, expression[i]);
            for(auto &e : addParentheses(left) ) {
                for(auto &r : addParentheses(right) ) {
                    string newExpr = e.toString() + op + r.toString();
                    results.push_back(stoi(newExpr));
                }
            }
        }
    }
    m[expression] = results;
    return results;
}

int main() {
    string s;
    getline(cin, s);
    vector<int> res = addParentheses(s);
    sort(res.begin(), res.end());
    for(int i : res) {
        cout << i << "\n";
    }
    return 0;
}

This code will handle the input string `expression` from the `main` function and print the results in non-decreasing order. The function `addParentheses` uses a map to store the results of the expressions it has already evaluated. The map is used to reduce redundant computation by checking if the result of the expression has already been calculated.