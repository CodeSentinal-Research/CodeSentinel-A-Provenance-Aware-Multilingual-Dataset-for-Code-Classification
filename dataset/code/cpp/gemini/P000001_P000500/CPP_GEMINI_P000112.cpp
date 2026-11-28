#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    if (std::cin >> n && n > 0) {
        std::set<int> unique_elements;
        for (int i = 0; i < n; i++) {
            int val;
            std::cin >> val;
            unique_elements.insert(val);
        }
        if (unique_elements.size() < 2) {
            std::cout << "Does not exist\n";
        } else {
            auto it = unique_elements.begin();
            ++it;
            std::cout << *it << "\n";
        }
    }
    return 0;
}