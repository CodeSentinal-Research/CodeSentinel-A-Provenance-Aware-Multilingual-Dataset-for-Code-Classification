#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string concatenate(string s1, string s2) { return s1 + s2; }
};
int main() {
    string s1, s2; cin >> s1 >> s2;
    cout << Solution().concatenate(s1, s2) << "\n";
}
