#include <iostream>
#include <vector>

void minHeapify(std::vector<int>& arr, int n, int i) {
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int main() {
    int n, m;
    if (std::cin >> n >> m) {
        std::vector<int> merged(n + m);
        for (int i = 0; i < n; i++) std::cin >> merged[i];
        for (int i = 0; i < m; i++) std::cin >> merged[n + i];
        for (int i = (n + m) / 2 - 1; i >= 0; i--) {
            minHeapify(merged, n + m, i);
        }
        for (size_t i = 0; i < merged.size(); i++) {
            std::cout << merged[i] << (i == merged.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}