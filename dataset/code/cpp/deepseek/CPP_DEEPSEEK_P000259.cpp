Here is the C++ solution:

#include <iostream>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;
    
    for(int i = 0; i < s.length(); i++) {
        s[i] = std::toupper(s[i]);
    }

    std::cout << s;
    return 0;
}

This code will take a string input from the user and convert all the characters in that string to uppercase using the toupper function from cctype library. The toupper function will convert a lowercase character to uppercase and will return the uppercase equivalent.