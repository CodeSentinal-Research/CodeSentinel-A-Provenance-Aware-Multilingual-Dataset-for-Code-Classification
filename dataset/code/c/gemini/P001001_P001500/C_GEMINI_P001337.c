#include <stdbool.h>

int backtrackArrangement(int pos, int n, bool visited[]) {
    if (pos > n) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
            visited[i] = true;
            count += backtrackArrangement(pos + 1, n, visited);
            visited[i] = false;
        }
    }
    return count;
}

int countArrangement(int n) {
    bool visited[20] = {false};
    return backtrackArrangement(1, n, visited);
}