Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateDiceRollSequences(int target) {
    if (target == 0) {
        cout << "{}" << endl;
        return;
    }

    for (int i = 1; i <= 6; i++) {
        if (target - i < 0) {
            break;
        }

        generateDiceRollSequences(target - i);

        cout << i << " ";
    }

    cout << endl;
}

int main() {
    int target;
    cout << "Enter the target: ";
    cin >> target;

    if (target < 1 || target > 20) {
        cout << "Invalid input" << endl;
        return 1;
    }

    cout << "All valid dice roll sequences:" << endl;
    generateDiceRollSequences(target);

    return 0;
}

This program uses recursion to generate all possible dice roll sequences. It takes the target value as input and recursively generates the sequences until it reaches 0. When a sequence is generated, it is printed in the lexicographical order. The base case is when the target is 0, in this case, it prints an empty set.