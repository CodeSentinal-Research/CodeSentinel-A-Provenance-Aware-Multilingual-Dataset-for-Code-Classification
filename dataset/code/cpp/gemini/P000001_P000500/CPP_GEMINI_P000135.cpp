#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (arr[mid] == 0) {
                std::swap(arr[low++], arr[mid++]);
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                std::swap(arr[mid], arr[high--]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) std::cout << " ";
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    return 0;
}