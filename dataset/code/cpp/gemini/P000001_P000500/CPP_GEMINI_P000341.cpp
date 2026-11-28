#include <iostream>
#include <string>

long long wordToVal(const std::string& w) {
    long long val = 0;
    for (char c : w) {
        val = val * 10 + (c - 'a');
    }
    return val;
}

int main() {
    std::string w1, w2, w3;
    if (std::cin >> w1 >> w2 >> w3) {
        std::cout << (wordToVal(w1) + wordToVal(w2) == wordToVal(w3) ? "Yes" : "No") << std::endl;
    }
    return 0;
}