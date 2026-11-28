#include <iostream>
#include <vector>
#include <sstream>

std::string encode(const std::vector<std::string>& strings) {
    std::stringstream ss;
    for(const auto& str : strings) {
        ss << str << ' ';
    }
    return ss.str();
}

std::vector<std::string> decode(const std::string& encodedStr) {
    std::vector<std::string> strings;
    std::stringstream ss(encodedStr);
    std::string str;
    while(getline(ss, str, ' ')) {
        strings.push_back(str);
    }
    return strings;
}

int main() {
    std::vector<std::string> strings = {"Hello", "World", "This", "is", "aC++", "Programming"};
    std::string encodedStr = encode(strings);
    std::vector<std::string> decodedStrings = decode(encodedStr);

    std::cout << "Encoded String: " << encodedStr << std::endl;

    for(const auto& str : decodedStrings) {
        std::cout << "Decoded String: " << str << std::endl;
    }

    return 0;
}