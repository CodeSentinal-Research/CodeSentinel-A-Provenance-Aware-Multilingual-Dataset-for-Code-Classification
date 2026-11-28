#include <iostream>
#include <vector>

std::pair<int, int> countEvenOdd(const std::vector<int>& arr) {
    int even = 0, odd = 0;
    for (int x : arr) {
        if (x % 2 == 0) even++;
        else odd++;
    }
    return {even, odd};
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        auto [even, odd] = countEvenOdd(arr);
        std::cout << "Even: " << even << ", Odd: " << odd << "\n";
    }
    return 0;
}