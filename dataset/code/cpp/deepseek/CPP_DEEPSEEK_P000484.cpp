Here is the C++ code for the problem:

#include <iostream>
#include <sstream>

std::string decodeString(std::string s) {
    int i = 0;
    std::string res = "";
    while (i < s.length()) {
        if (s[i] == '[') {
            i++;
            std::string temp = "";
            while (s[i] != ']') {
                temp += s[i];
                i++;
            }
            i++;
            int repeat = std::stoi(temp);
            std::string toRepeat = res.substr(res.length() - repeat, repeat);
            res.erase(res.length() - repeat, repeat);
            res += toRepeat;
        } else {
            res += s[i];
            i++;
        }
    }
    return res;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << decodeString(s);
    return 0;
}

This code reads a string from the standard input, decodes it by iterating over each character in the string, and if it encounters a character inside square brackets, it extracts the number before the ']' and repeats the extracted substring k times. If the character is not inside square brackets, it simply appends the character to the result string.