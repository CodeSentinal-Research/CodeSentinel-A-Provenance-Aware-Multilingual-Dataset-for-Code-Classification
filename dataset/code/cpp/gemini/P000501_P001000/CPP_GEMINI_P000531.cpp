#include <iostream>
#include <vector>
#include <queue>
int main() {
    int n;
    if (std::cin >> n) {
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            int t;
            std::cin >> t;
            q.push(t);
            while (!q.empty() && q.front() < t - 3000) q.pop();
            std::cout << q.size() << std::endl;
        }
    }
    return 0;
}