#include <iostream>
#include <string>
#include <unordered_map>
int main() {
    std::string s;
    if (std::cin >> s) {
        std::unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        for (size_t i = 0; i < s.length(); i++) {
            int val = map[s[i]];
            if (i + 1 < s.length() && val < map[s[i + 1]]) total -= val;
            else total += val;
        }
        std::cout << total << std::endl;
    }
    return 0;
}