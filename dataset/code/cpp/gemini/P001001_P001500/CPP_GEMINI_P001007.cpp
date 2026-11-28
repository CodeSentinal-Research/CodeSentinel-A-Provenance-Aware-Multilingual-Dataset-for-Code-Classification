#include <iostream>
#include <vector>

void maxHeapify(std::vector<int>& arr, int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void replaceRoot(std::vector<int>& arr, int x) {
    arr[0] = x;
    maxHeapify(arr, arr.size(), 0);
}

int main() {
    int n, x;
    if (std::cin >> n >> x && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        replaceRoot(arr, x);
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}