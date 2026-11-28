#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> deck(n);
        for (int i = 0; i < n; i++) std::cin >> deck[i];
        std::sort(deck.begin(), deck.end());
        std::queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        std::vector<int> res(n);
        for (int card : deck) {
            res[q.front()] = card;
            q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        for (int i = 0; i < n; i++) std::cout << res[i] << (i == n - 1 ? "" : " ");
        std::cout << std::endl;
    }
    return 0;
}