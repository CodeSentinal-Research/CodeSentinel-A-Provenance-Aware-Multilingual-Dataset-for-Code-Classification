Here is the code:

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_set<string> uniqueStrings;
    for(int i = 0; i < s.size(); i++) {
        string temp = "";
        temp += s[i];
        uniqueStrings.insert(temp);
        for(int j = i + 1; j < s.size(); j++) {
            temp += s[j];
            uniqueStrings.insert(temp);
        }
    }

    cout << uniqueStrings.size() << endl;

    return 0;
}

This code splits the input string into unique substrings. It iterates through each character in the string, and for each character, it adds it to a temporary string and adds the temporary string to the set of unique substrings. It then iterates through all the remaining characters in the string, adding them to the temporary string until the end.

The size of the set of unique substrings is the maximum number of unique substrings that can be created from the string. The code then prints this number.