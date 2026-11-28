#include <iostream>
#include <vector>

int findLastOccurrence(const std::vector<int>& arr, int x) {
    int n = arr.size();
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    int x;
    std::cin >> x;
    int result = findLastOccurrence(arr, x);
    std::cout << result << std::endl;
    return 0;
}