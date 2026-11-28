#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

double arrayAverage(const std::vector<double>& arr) {
    if (arr.empty()) return 0.0;
    double sum = std::accumulate(arr.begin(), arr.end(), 0.0);
    return sum / arr.size();
}

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::vector<double> arr(n);
        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }
        std::cout << std::fixed << std::setprecision(2) << arrayAverage(arr) << "\n";
    }
    return 0;
}