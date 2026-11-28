#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int stringLength(const string& s) { return s.size(); }
};
int main() {
    string s; cin >> s;
    cout << Solution().stringLength(s) << "\n";
}
