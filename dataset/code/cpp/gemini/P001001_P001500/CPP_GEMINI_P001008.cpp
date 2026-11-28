#include <iostream>
#include <vector>

int main() {
    int n, val;
    if (std::cin >> n >> val) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        arr.push_back(val);
        int i = arr.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (arr[i] < arr[p]) {
                std::swap(arr[i], arr[p]);
                i = p;
            } else {
                break;
            }
        }
        for (size_t j = 0; j < arr.size(); j++) {
            std::cout << arr[j] << (j == arr.size() - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
    return 0;
}