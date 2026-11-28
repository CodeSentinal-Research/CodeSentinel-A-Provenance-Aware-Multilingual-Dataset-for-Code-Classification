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
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        if (n > 1) {
            arr[0] = arr.back();
            arr.pop_back();
            maxHeapify(arr, arr.size(), 0);
        } else {
            arr.pop_back();
        }
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}