#include <iostream>
void dfs(int cur, int n) {
    if (cur > n) return;
    std::cout << cur << std::endl;
    for (int i = 0; i < 10; i++) {
        if (cur * 10 + i <= n) dfs(cur * 10 + i, n);
        else break;
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        for (int i = 1; i <= 9 && i <= n; i++) dfs(i, n);
    }
    return 0;
}