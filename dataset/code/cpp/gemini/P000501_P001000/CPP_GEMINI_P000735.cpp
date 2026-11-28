#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
void gen_k_strings(const std::vector<char>& chars, int k, std::string cur) {
    if ((int)cur.length() == k) {
        std::cout << cur << std::endl;
        return;
    }
    for (char c : chars) {
        gen_k_strings(chars, k, cur + c);
    }
}
int main() {
    int n;
    if (std::cin >> n) {
        std::vector<char> chars(n);
        for (int i = 0; i < n; i++) std::cin >> chars[i];
        int k; std::cin >> k;
        std::sort(chars.begin(), chars.end());
        gen_k_strings(chars, k, "");
    }
    return 0;
}