#include <iostream>
#include <vector>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        int x;
        std::cin >> x;
        int count = 0;
        for (int v : arr) if (v == x) count++;
        std::cout << count << std::endl;
    }
    return 0;
}