#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    int n, target;
    if (std::cin >> n >> target) {
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        std::sort(arr.begin(), arr.end());
        bool found = false;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int s = arr[i] + arr[l] + arr[r];
                if (s == target) { found = true; break; }
                else if (s < target) l++;
                else r--;
            }
            if (found) break;
        }
        std::cout << (found ? "Yes" : "No") << std::endl;
    }
    return 0;
}