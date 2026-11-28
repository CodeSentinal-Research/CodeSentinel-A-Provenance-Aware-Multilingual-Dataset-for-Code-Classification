#include <iostream>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> nums(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }

    int max_odd = -1;
    int count = 0;
    for(int i = 0; i < N; ++i) {
        if(nums[i] % 2 == 1) {
            count++;
            if(count == K) {
                max_odd = std::max(max_odd, nums[i]);
                count--;
            }
        } else {
            count = 0;
        }
    }

    std::cout << max_odd << std::endl;

    return 0;
}