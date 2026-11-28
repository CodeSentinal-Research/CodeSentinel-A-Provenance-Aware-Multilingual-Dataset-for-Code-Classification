#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, string> phoneMap = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

void generate(string digits, int index, string current, vector<string>& result) {
    if (index == digits.length()) {
        if (!current.empty()) result.push_back(current);
        return;
    }
    string letters = phoneMap[digits[index]];
    for (char c : letters) {
        generate(digits, index + 1, current + c, result);
    }
}

int main() {
    string digits;
    cin >> digits;
    vector<string> result;
    generate(digits, 0, "", result);
    
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
