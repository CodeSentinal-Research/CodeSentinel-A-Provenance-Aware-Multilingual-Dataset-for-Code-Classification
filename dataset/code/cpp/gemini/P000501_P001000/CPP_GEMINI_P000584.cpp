#include <iostream>
#include <vector>
int main() {
    int size;
    if (std::cin >> size) {
        std::vector<int> vals(size);
        for (int i = 0; i < size; i++) std::cin >> vals[i];
        int n; std::cin >> n;
        vals.erase(vals.begin() + (size - n));
        for (size_t i = 0; i < vals.size(); i++) {
            std::cout << vals[i] << (i + 1 == vals.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}