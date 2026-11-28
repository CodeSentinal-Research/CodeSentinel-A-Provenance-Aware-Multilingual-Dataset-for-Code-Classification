#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void generateParentheses(int n, int open, int close, string output, vector<string>& results) {
    if (n == open && n == close) {
        results.push_back(output);
        return;
    }
    if (open < n) {
        generateParentheses(n, open + 1, close, output + "(", results);
    }
    if (close < open) {
        generateParentheses(n, open, close + 1, output + ")", results);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> results;
    generateParentheses(n, 0, 0, "", results);
    for (string result : results) {
        cout << result << endl;
    }
    return 0;
}
This program uses the Depth-First Search (DFS) approach to generate all the possible results from computing all the different possible ways to group numbers and operators. It takes the number of parentheses to be added as input, and then recursively adds parentheses to the left and right sides of the expression until it has added all the parentheses.

The main function reads the number of parentheses to be added, and then calls the `generateParentheses` function to start the DFS. The `generateParentheses` function takes the number of open parentheses, close parentheses, current output, and a list of results as arguments. It first checks if the number of open parentheses and close parentheses are equal. If they are, it adds the current output to the results. If the number of open parentheses is less than the number of parentheses to be added, it adds a left parenthesis to the output and recursively calls `generateParentheses` to add a right parenthesis. If the number of close parentheses is less than the number of open parentheses, it adds a right parenthesis to the output and recursively calls `generateParentheses` to add a left parenthesis.

The main function then prints out all the possible results.