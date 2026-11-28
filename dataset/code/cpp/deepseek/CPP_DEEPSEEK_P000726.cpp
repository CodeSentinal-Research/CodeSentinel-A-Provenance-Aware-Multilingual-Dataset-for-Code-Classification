Here is the C++ code that generates all valid arithmetic expressions from a given string. This code uses a recursive function to generate all possible expressions. The expressions are then printed in a depth-first manner.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateParentheses(int n) {
    if (n == 0) {
        return vector<string>({""});
    } else {
        vector<string> results;
        for (int i = 0; i < n; i++) {
            for (auto &s : generateParentheses(i)) {
                for (auto &t : generateParentheses(n-i-1)) {
                    results.push_back("(" + s + " + " + t + ")");
                    results.push_back("(" + s + " - " + t + ")");
                    results.push_back("(" + s + " * " + t + ")");
                }
            }
        }
        return results;
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> results = generateParentheses(n);
    for (auto &s : results) {
        cout << s << endl;
    }
    return 0;
}

This code works by recursively generating the expression for the prefix part (the part of the string before the first operation) and then recursively generating the expression for the rest of the string (the part of the string after the first operation). The recursion is done by iterating over all possible combinations of generating prefix expressions.

Please note that this code has a large time complexity due to the recursive nature of the algorithm. Also, the code assumes that the input string represents a valid arithmetic expression with no more operators than the number of digits, because otherwise the code would be stuck in an infinite loop.