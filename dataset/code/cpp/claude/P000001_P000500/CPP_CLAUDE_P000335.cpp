#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Solution {
public:
    string toggleCase(string s) {
        for (char& c : s)
            c = isupper(c) ? tolower(c) : toupper(c);
        return s;
    }
};
int main() {
    string s; cin >> s;
    cout << Solution().toggleCase(s) << "\n";
}
