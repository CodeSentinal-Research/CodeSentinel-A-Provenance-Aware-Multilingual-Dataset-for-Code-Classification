#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }
};
int main() {
    string s; cin >> s;
    cout << (Solution().isPalindrome(s) ? "Yes" : "No") << "\n";
}
