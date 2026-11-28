Here is the code:

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

bool isKeyboardRow(const std::unordered_set<char>& row) {
    const std::unordered_set<char> keyboardRow1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    const std::unordered_set<char> keyboardRow2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    const std::unordered_set<char> keyboardRow3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    for (char c : row) {
        if (keyboardRow1.find(tolower(c)) != keyboardRow1.end()) return true;
        if (keyboardRow2.find(tolower(c)) != keyboardRow2.end()) return false;
        if (keyboardRow3.find(tolower(c)) != keyboardRow3.end()) return false;
    }

    return true;
}

int main() {
    std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};

    for (const std::string& word : words) {
        std::unordered_set<char> row;
        for (char c : word) {
            row.insert(tolower(c));
        }

        if (isKeyboardRow(row)) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
This program first defines a set of characters for each row of the keyboard. It then iterates over each word, converting all characters to lowercase and checking if they are in any of the sets. If they are, it means they can be typed on that row.