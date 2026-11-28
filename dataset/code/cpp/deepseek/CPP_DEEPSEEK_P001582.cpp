#include <iostream>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    
    int start = 0, end = 0;
    int maxLen = 0;
    int count = 0;
    
    while (end < N) {
        if (arr[end] == 0) {
            count++;
        }
        
        while (count > K) {
            if (arr[start] == 0) {
                count--;
            }
            start++;
        }
        
        maxLen = std::max(maxLen, end - start + 1);
        end++;
    }
    
    std::cout << maxLen;
    return 0;
}