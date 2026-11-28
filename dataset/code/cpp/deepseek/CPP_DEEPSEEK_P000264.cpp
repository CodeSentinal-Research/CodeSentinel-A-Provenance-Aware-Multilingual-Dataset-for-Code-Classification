#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    map<char, int> frequency;

    for(char c : s) {
        frequency[c]++;
    }

    for(auto const& pair : frequency) {
        cout << pair.first << " : " << pair.second << '\n';
    }

    return 0;
}