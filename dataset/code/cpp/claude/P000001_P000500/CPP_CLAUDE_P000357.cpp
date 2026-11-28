#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    map<char,int> countChars(string s) {
        map<char,int> freq;
        for (char c : s) freq[c]++;
        return freq;
    }
};
int main() {
    string s; cin >> s;
    auto f = Solution().countChars(s);
    for (auto& [k,v] : f) cout << k << ": " << v << "\n";
}
