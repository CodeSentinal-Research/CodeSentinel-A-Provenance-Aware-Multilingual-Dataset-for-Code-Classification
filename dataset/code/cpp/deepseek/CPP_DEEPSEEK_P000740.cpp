Sure, here is the complete C++ code for the problem:

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printPaths(int n, int m, string path) {
    if (n == 1 && m == 1) {
        cout << path << endl;
        return;
    }

    if (n > 1) {
        printPaths(n-1, m, path + "V");
    }

    if (m > 1) {
        printPaths(n, m-1, path + "H");
    }
}

int main() {
    int n, m;
    cout << "Enter the dimensions (N M): ";
    cin >> n >> m;

    printPaths(n, m, "");

    return 0;
}
This code will print all possible paths from the top-left cell to the bottom-right cell in a lexicographical order. The `printPaths` function recursively generates all possible paths. It takes the dimensions `n` and `m` of the grid and a string `path` that represents the current path. If `n` and `m` are both 1, it prints the path. Otherwise, it recursively calls `printPaths` with `n-1` and `m` and appends 'V' to the path. Similarly, it recursively calls `printPaths` with `n` and `m-1` and appends 'H' to the path.

Please note that this code prints paths in lexicographical order, i.e., it prints paths in the order 'V' (down) and 'H' (right) are followed.