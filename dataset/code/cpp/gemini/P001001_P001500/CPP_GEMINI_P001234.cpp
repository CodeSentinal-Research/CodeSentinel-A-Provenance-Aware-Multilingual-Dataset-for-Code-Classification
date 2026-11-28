#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> arr(n), dep(n);
        for (int i = 0; i < n; i++) std::cin >> arr[i];
        for (int i = 0; i < n; i++) std::cin >> dep[i];

        std::sort(arr.begin(), arr.end());
        std::sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int platNeeded = 0, maxPlat = 0;

        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platNeeded++;
                maxPlat = std::max(maxPlat, platNeeded);
                i++;
            } else {
                platNeeded--;
                j++;
            }
        }
        std::cout << maxPlat << "\n";
    }
    return 0;
}