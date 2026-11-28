#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    int m;
    cin >> m;
    vector<string> words(m);
    for(int i = 0; i < m; i++) {
        cin >> words[i];
    }
    int count = 0;
    for(const string &word : words) {
        int j = 0;
        for(int i = 0; i < word.size(); i++) {
            if(j == S.size()) break;
            if(S[j] == word[i]) j++;
        }
        if(j == S.size()) count++;
    }
    cout << count;
    return 0;
}