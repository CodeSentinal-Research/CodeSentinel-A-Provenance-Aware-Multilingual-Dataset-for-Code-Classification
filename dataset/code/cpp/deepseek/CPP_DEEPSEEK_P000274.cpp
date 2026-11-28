#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
    if(needle.empty()) return 0;
    if(haystack.empty()) return -1;
    if(haystack.size() < needle.size()) return -1;

    for(int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
        if(haystack.substr(i, needle.size()) == needle)
            return i;
    }

    return -1;
}

int main() {
    string haystack, needle;
    cout << "Enter haystack: ";
    cin >> haystack;
    cout << "Enter needle: ";
    cin >> needle;

    int result = strStr(haystack, needle);
    cout << "Index: " << result << endl;

    return 0;
}