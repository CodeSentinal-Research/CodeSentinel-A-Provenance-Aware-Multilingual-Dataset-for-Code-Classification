#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int count = 0;
    int left_sum = 0;
    int right_sum = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            left_sum += arr[i-1];
        }
        if (i < n - 1) {
            right_sum += arr[i+1];
        }
        if (left_sum == right_sum && i > 0 && i < n - 1) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
This C++ code reads the number of elements `n` and the array of integers from the standard input. It then calculates the sum of the elements to its left and right for each index. If the sums are equal at any index, it increments the count. The final count of pivot indices is printed to the standard output.