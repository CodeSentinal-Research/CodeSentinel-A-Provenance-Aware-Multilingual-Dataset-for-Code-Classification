#include <iostream>
int kth_grammar(int n, int k) {
    if (n == 1) return 0;
    int parent = kth_grammar(n - 1, (k + 1) / 2);
    if (parent == 0) return (k % 2 != 0 ? 0 : 1);
    else return (k % 2 != 0 ? 1 : 0);
}
int main() {
    int n, k;
    if (std::cin >> n >> k) {
        std::cout << kth_grammar(n, k) << std::endl;
    }
    return 0;
}