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
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        for (int i = n / 2 - 1; i >= 0; i--) minHeapify(arr, n, i);
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}