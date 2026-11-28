Here is the C++ code snippet for the given problem.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heap;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        heap.push_back(num);
    }

    int i;
    cin >> i;

    int level = 0;
    while (i != 0) {
        i = (i + 1) / 2;
        level++;
    }

    cout << level << endl;

    return 0;
}

In this code, we first take the size of the heap as input. Then, we take the values of the heap as input and store them in a vector. We then take the index of the node as input and calculate the level of the node. The level of the node is calculated by dividing the index by 2 until the index becomes 0. We then print the level of the node.