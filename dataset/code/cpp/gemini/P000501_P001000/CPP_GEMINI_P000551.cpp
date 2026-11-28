#include <iostream>
#include <string>
#include <queue>
int main() {
    int n;
    if (std::cin >> n) {
        std::queue<std::string> q;
        q.push("1");
        for (int i = 1; i <= n; i++) {
            std::string cur = q.front(); q.pop();
            std::cout << cur << (i == n ? "" : " ");
            q.push(cur + "0");
            q.push(cur + "1");
        }
        std::cout << std::endl;
    }
    return 0;
}