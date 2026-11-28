#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
int main() {
    int n1, n2, n3;
    if (std::cin >> n1 >> n2 >> n3) {
        std::vector<int> a(n1), b(n2), c(n3);
        for (int i = 0; i < n1; i++) std::cin >> a[i];
        for (int i = 0; i < n2; i++) std::cin >> b[i];
        for (int i = 0; i < n3; i++) std::cin >> c[i];
        int i = 0, j = 0, k = 0;
        std::set<int> res;
        while (i < n1 && j < n2 && k < n3) {
            if (a[i] == b[j] && b[j] == c[k]) {
                res.insert(a[i]);
                i++; j++; k++;
            } else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }
        if (res.empty()) std::cout << -1 << std::endl;
        else {
            bool first = true;
            for (int val : res) {
                if (!first) std::cout << " ";
                std::cout << val;
                first = false;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}