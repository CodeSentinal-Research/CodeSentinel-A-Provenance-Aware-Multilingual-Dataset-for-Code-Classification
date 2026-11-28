#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void generateStrings(vector<char>& chars, int k, string current, vector<string>& result) {
    if (k == 0) {
        result.push_back(current);
        return;
    }
    for (char c : chars) {
        generateStrings(chars, k - 1, current + c, result);
    }
}

int main() {
    int n, k;
    cin >> n;
    vector<char> chars(n);
    for (int i = 0; i < n; ++i) cin >> chars[i];
    cin >> k;
    
    sort(chars.begin(), chars.end());
    vector<string> result;
    generateStrings(chars, k, "", result);
    
    for (const string& s : result) {
        cout << s << endl;
    }
    return 0;
}
