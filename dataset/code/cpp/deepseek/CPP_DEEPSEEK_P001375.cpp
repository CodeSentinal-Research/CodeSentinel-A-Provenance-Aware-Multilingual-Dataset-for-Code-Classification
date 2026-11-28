#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length())
        return false;
    
    unordered_map<char, int> count;

    for(int i = 0; i < s.length(); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    for(auto pair: count) {
        if(pair.second != 0)
            return false;
    }

    return true;
}

int main() {
    string s, t;
    cin >> s >> t;
    
    if(isAnagram(s, t))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}