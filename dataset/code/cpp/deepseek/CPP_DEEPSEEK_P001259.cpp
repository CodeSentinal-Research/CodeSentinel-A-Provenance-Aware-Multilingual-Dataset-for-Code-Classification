Here is the C++ code for the problem:

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int minimumSwaps(string str) {
    stack<char> s;
    int swapCount = 0;

    for (char c : str) {
        if (c == '[') {
            s.push(c);
        } else {
            if (s.empty()) {
                swapCount++;
            } else {
                s.pop();
            }
        }
    }

    return swapCount;
}

int main() {
    string str;
    cin >> str;
    cout << minimumSwaps(str);
    return 0;
}

This code works by using a stack to keep track of the opening brackets. If it encounters an opening bracket, it pushes it onto the stack. If it encounters a closing bracket, it pops the top element from the stack (which should be an opening bracket) and increments the swap count. If the stack is empty after popping, it means there is an unbalanced pair of brackets, so we increment the swap count. Finally, it returns the total number of swaps required.