#include <iostream>
#include <vector>

void decreaseKey(std::vector<int>& arr, int idx, int newVal) {
    arr[idx] = newVal;
    int i = idx;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (arr[i] < arr[p]) {
            std::swap(arr[i], arr[p]);
            i = p;
        } else {
            break;
        }
    }
}

int main() {
    int n, idx, newVal;
    if (std::cin >> n >> idx >> newVal && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        decreaseKey(arr, idx, newVal);
        for (int i = 0; i < n; i++) {
            std::cout << arr[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}