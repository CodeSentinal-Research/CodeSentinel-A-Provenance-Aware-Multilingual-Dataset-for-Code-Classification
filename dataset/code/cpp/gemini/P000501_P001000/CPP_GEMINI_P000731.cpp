#include <iostream>
#include <vector>
int total_count = 0;
void backtrack(int n, int r, std::vector<bool>& cols, std::vector<bool>& d1, std::vector<bool>& d2) {
    if (r == n) { total_count++; return; }
    for (int c = 0; c < n; c++) {
        if (cols[c] || d1[r + c] || d2[r - c + n]) continue;
        cols[c] = d1[r + c] = d2[r - c + n] = true;
        backtrack(n, r + 1, cols, d1, d2);
        cols[c] = d1[r + c] = d2[r - c + n] = false;
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<bool> cols(n, false), d1(2 * n, false), d2(2 * n, false);
        backtrack(n, 0, cols, d1, d2);
        std::cout << total_count << std::endl;
    }
    return 0;
}