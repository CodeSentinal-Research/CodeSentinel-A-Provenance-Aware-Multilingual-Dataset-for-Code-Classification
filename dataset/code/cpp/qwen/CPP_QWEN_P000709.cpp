#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void generatePermutations(string s, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(s);
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);
            generatePermutations(s, l + 1, r, result);
            swap(s[l], s[i]); // backtrack
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<string> result;
    generatePermutations(s, 0, s.length() - 1, result);
    sort(result.begin(), result.end());
    // Remove duplicates if any (though problem says distinct chars)
    for (const string& perm : result) {
        cout << perm << endl;
    }
    return 0;
}
