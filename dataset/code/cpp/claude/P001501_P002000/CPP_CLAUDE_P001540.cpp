#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int countVowels(string s) {
        string vowels = "aeiouAEIOU";
        int count = 0;
        for (char c : s)
            if (vowels.find(c) != string::npos) count++;
        return count;
    }
};
int main() {
    string s; getline(cin, s);
    cout << Solution().countVowels(s) << "\n";
}
