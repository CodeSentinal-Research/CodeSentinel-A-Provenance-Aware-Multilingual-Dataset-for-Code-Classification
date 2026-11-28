Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }
    int count = 0;
    while (m['b'] > 0 && m['a'] > 0) {
        m['b']--;
        m['a']--;
        count++;
    }
    if (m['b'] > 0 || m['a'] > 0) {
        cout << count << endl;
    } else {
        cout << count + 1 << endl;
    }
    return 0;
}

This code works by creating an unordered map to count the occurrences of each character in the string. It then repeatedly removes one occurrence of 'a' and one occurrence of 'b' from the map until there are no more of either character left. At the end, it checks if there are any remaining characters in the map (which means that there was an instance of 'a' and 'b' left), and if so, it prints the number of instances plus one (for the remaining 'b' and 'a' pair). Otherwise, it prints the number of instances.