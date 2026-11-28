#include <iostream>
#include <vector>
int backtrack(int pos, int n, std::vector<bool>& used) {
    if (pos > n) return 1;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && (i % pos == 0 || pos % i == 0)) {
            used[i] = true;
            count += backtrack(pos + 1, n, used);
            used[i] = false;
        }
    }
    return count;
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<bool> used(n + 1, false);
        std::cout << backtrack(1, n, used) << std::endl;
    }
    return 0;
}