Here is the C++ code:

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int findMinOperations(vector<string>& folderOperations) {
    stack<string> folderStack;
    int operations = 0;

    for (string operation : folderOperations) {
        if (operation == "../") {
            if (!folderStack.empty()) {
                folderStack.pop();
            }
        } else if (operation == "./") {
        } else {
            folderStack.push(operation);
        }
    }

    while (!folderStack.empty()) {
        folderStack.pop();
        operations++;
    }

    return operations;
}

int main() {
    int n;
    cin >> n;

    vector<string> folderOperations(n);

    for (int i = 0; i < n; i++) {
        cin >> folderOperations[i];
    }

    int minOperations = findMinOperations(folderOperations);
    cout << minOperations << endl;

    return 0;
}
This code reads the number of folder operations and their values from the user. It then calls the `findMinOperations` function, which returns the minimum number of operations needed to return to the main folder. The result is then printed to the console.