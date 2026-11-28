Here is the code:

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int n, int open, int close, string s, vector<string> &result) {
    if (n == 0) {
        result.push_back(s);
        return;
    }
    if (open < n) {
        generateParentheses(n, open+1, close, s+'(', result);
    }
    if (close < open) {
        generateParentheses(n, open, close+1, s+')', result);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n > 8 || n < 1) {
        cout << "Input should be between 1 and 8";
        return 0;
    }
    vector<string> result;
    generateParentheses(n, 0, 0, "", result);
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}

This program uses a recursive approach to generate all the combinations of parentheses of given length. It starts by checking if the current length is 0, if it is, it adds the current string to the result. If the current length is less than the given length, it recursively calls for adding an open parenthesis and closing parenthesis.