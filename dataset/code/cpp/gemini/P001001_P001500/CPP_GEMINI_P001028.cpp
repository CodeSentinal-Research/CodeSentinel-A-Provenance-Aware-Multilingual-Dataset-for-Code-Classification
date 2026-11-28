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

int main() {
    int n, idx;
    if (std::cin >> n >> idx && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        arr[idx] = arr.back();
        arr.pop_back();
        if (idx < (int)arr.size()) {
            int cur = idx;
            while (cur > 0 && arr[cur] > arr[(cur - 1) / 2]) {
                std::swap(arr[cur], arr[(cur - 1) / 2]);
                cur = (cur - 1) / 2;
            }
            maxHeapify(arr, arr.size(), cur);
        }
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}