#include <iostream>
#include <unordered_map>

int main() {
    int N;
    std::cin >> N;

    std::unordered_map<int, int> map;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; i++) {
        int num;
        std::cin >> num;

        sum += num;

        if (sum == 0) {
            maxLen = i + 1;
        } else if (map.find(sum) != map.end()) {
            if (maxLen < i - map[sum]) {
                maxLen = i - map[sum];
            }
        } else {
            map[sum] = i;
        }
    }

    std::cout << maxLen;

    return 0;
}