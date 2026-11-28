#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n), res(n, 0);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[i]) res[i]++;
            }
        }
        for (int i = 0; i < n; i++) {
            std::cout << res[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}