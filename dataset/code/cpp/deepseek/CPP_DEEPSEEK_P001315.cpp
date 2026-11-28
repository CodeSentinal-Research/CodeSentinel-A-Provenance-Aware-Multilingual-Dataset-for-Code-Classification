Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>

using namespace std;

int N;
int path[21][21];
vector<string> result;

void DFS(int x, int y) {
    if (x == N && y == N) {
        string s = "";
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                s += to_string(path[i][j]);
            }
        }
        result.push_back(s);
        return;
    }
    if (x > N || y > N) return;
    if (path[x][y]) DFS(x, y + 1);
    else if (x < N && path[x + 1][y]) DFS(x + 1, y);
    else if (y < N && path[x][y + 1]) DFS(x, y + 1);
    path[x][y] = 1;
    DFS(x, y + 1);
    path[x][y] = 0;
}

int main() {
    cin >> N;
    DFS(1, 1);
    sort(result.begin(), result.end());
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}

This code solves the problem by using a depth-first search algorithm. It starts from the top-left corner (1, 1) and then recursively explore all possible paths by moving up, down, left or right until it reaches the bottom-right corner (N, N). For each path, it converts the path into a string and adds it to the result.

The input handling part is done in the main function. It first reads the value of N, and then calls the DFS function. Finally, it sorts the result and prints all the valid paths in lexicographical order.