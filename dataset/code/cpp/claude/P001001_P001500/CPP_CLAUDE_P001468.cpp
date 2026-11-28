#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
int main() {
    string s; cin >> s;
    cout << Solution().reverseString(s) << "\n";
}
