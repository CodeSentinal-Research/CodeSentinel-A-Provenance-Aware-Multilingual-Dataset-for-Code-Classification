#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[i]) {
                maxLength = std::max(maxLength, j - i + 1);
            }
        }
    }
    std::cout << maxLength;
    return 0;
}
This C++ program reads an integer N and a sequence of N integers from the standard input. It then calculates the length of the longest decreasing subarray by checking all possible subarrays and updating the maximum length as needed. Finally, it outputs the maximum length.