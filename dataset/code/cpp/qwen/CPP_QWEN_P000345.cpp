#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    unordered_map<char, int> c1, c2;
    for (char c : s1) c1[c]++;
    for (char c : s2) c2[c]++;
    cout << (c1 == c2 ? "Yes" : "No") << endl;
    return 0;
}
