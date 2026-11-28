#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

string removeDuplicateLetters(string s) {
    stack<char> stk;
    vector<int> freq(26, 0);
    for(auto ch: s) freq[ch - 'a']++;
    for(int i = 0; i < s.size(); i++){
        freq[s[i] - 'a']--;
        if(stk.find(s[i]) != stk.end()) continue;
        while(!stk.empty() && stk.top() > s[i] && freq[stk.top() - 'a'] > 0){
            stk.pop();
        }
        stk.push(s[i]);
    }
    string res = "";
    while(!stk.empty()){
        res = stk.top() + res;
        stk.pop();
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    string res = removeDuplicateLetters(s);
    cout << res;
    return 0;
}