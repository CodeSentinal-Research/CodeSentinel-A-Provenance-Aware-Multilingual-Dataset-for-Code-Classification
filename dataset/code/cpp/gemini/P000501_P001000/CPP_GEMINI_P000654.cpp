#include <iostream>
#include <vector>
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<int> vals(n);
        for (int i = 0; i < n; i++) std::cin >> vals[i];
        int pivot = vals[n - 1];
        std::vector<int> less, greater;
        for (int i = 0; i < n - 1; i++) {
            if (vals[i] < pivot) less.push_back(vals[i]);
            else greater.push_back(vals[i]);
        }
        for (int x : less) std::cout << x << " ";
        std::cout << pivot;
        for (int x : greater) std::cout << " " << x;
        std::cout << std::endl;
    }
    return 0;
}