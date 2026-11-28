#include <iostream>
#include <string>

int main() {
    std::string s;
    char old_char, new_char;

    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    std::cout << "Enter the character to be replaced: ";
    std::cin >> old_char;

    std::cout << "Enter the new character: ";
    std::cin >> new_char;

    for(size_t i = 0; i < s.length(); ++i) {
        if(s[i] == old_char) {
            s[i] = new_char;
        }
    }

    std::cout << "Modified string: " << s << std::endl;

    return 0;
}