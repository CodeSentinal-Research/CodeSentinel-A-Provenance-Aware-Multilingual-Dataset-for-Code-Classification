#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
    }
    return 0;
}

void solve(vector<int> numbers, vector<char> ops, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        cout << numbers[startIndex] << " ";
        return;
    }

    if (startIndex + 1 == endIndex) {
        cout << "(" << calculate(numbers[startIndex], numbers[startIndex + 1], ops[startIndex]) << " " << numbers[startIndex + 1] << " ";
        return;
    }

    for (int i = startIndex + 1; i <= endIndex; i++) {
        cout << "(" << calculate(numbers[startIndex], numbers[i], ops[startIndex]) << " " << numbers[i];
        solve(numbers, ops, startIndex + 1, i - 1);
        cout << " " << calculate(numbers[startIndex], numbers[i], ops[startIndex]) << " " << numbers[i] << ") ";
    }
}

int main() {
    string expression;
    cin >> expression;

    vector<int> numbers;
    vector<char> ops;

    for (int i = 0; i < expression.size(); i += 2) {
        numbers.push_back(expression[i] - '0');
        if (i + 1 < expression.size()) {
            ops.push_back(expression[i + 1]);
        }
    }

    solve(numbers, ops, 0, numbers.size() - 1);

    return 0;
}