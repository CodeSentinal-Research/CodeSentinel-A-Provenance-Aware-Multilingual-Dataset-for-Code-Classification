#include <iostream>
#include <vector>
#include <string>
#include <sstream>
int main() {
    std::string line1, line2;
    if (std::getline(std::cin, line1)) {
        std::vector<int> l1, l2;
        std::stringstream ss1(line1);
        int v; while (ss1 >> v) l1.push_back(v);
        if (std::getline(std::cin, line2)) {
            std::stringstream ss2(line2);
            while (ss2 >> v) l2.push_back(v);
        }
        if (!l1.empty() && (int)l1.size() - 1 == l1[0]) l1.erase(l1.begin());
        if (!l2.empty() && (int)l2.size() - 1 == l2[0]) l2.erase(l2.begin());
        std::vector<int> res;
        int carry = 0, i = 0, j = 0;
        while (i < (int)l1.size() || j < (int)l2.size() || carry) {
            int v1 = (i < (int)l1.size()) ? l1[i] : 0;
            int v2 = (j < (int)l2.size()) ? l2[j] : 0;
            int sum = v1 + v2 + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            i++; j++;
        }
        for (size_t k = 0; k < res.size(); k++) {
            std::cout << res[k] << (k + 1 == res.size() ? "" : " ");
        }
        std::cout << std::endl;
    }
    return 0;
}