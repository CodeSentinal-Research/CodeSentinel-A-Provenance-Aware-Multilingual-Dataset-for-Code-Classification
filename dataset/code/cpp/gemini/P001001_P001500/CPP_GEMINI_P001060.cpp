#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, k;
    if (std::cin >> n >> k && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int idx = 0;
        for (int i = 0; i <= std::min(k, n - 1); i++) pq.push(arr[i]);
        for (int i = k + 1; i < n; i++) {
            arr[idx++] = pq.top(); pq.pop();
            pq.push(arr[i]);
        }
        while (!pq.empty()) {
            arr[idx++] = pq.top(); pq.pop();
        }
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}