#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> camelMatch(vector<string>& queries, string pattern) {
    vector<bool> res;
    for (string &q : queries) {
        int p = 0, q = 0;
        while (p < q && q < pattern.size()) {
            if (q[q++] == pattern[p]) p++;
            else break;
        }
        while (q < pattern.size()) {
            if (q[q++] != pattern[p]) break;
            p++;
        }
        res.push_back(p == pattern.size() && q == pattern.size());
    }
    return res;
}

int main() {
    vector<string> queries = {"FooBar", "Foo", "FooBar", "FooBaz"};
    string pattern = "FoBa";
    vector<bool> res = camelMatch(queries, pattern);
    for (bool b : res) {
        cout << b << " ";
    }
    return 0;
}