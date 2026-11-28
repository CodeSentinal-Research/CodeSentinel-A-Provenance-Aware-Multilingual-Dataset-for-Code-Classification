#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        std::unordered_set<char> charSet;
        for (char c : strings[i]) {
            charSet.insert(c);
        }

        for (int j = 0; j < i; ++j) {
            if (strings[i].size() != strings[j].size()) {
                continue;
            }

            std::unordered_set<char> otherCharSet;
            for (char c : strings[j]) {
                otherCharSet.insert(c);
            }

            if (charSet == otherCharSet) {
                ++count;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}