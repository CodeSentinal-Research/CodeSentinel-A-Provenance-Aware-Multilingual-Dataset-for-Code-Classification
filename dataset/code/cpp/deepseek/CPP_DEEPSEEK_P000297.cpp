#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s) {
    map<char, int> val = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int result = 0, prev = 0;

    for(char c: s) {
        int curr = val[c];
        result += curr;
        if(curr > prev) {
            result -= 2 * prev;
        }
        prev = curr;
    }

    return result;
}

int main() {
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}