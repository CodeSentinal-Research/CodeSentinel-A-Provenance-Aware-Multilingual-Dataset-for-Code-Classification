#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Union Find for transitive similarity
struct DSU {
    unordered_map<string, string> parent;
    string find(string x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(string x, string y) {
        parent[find(x)] = find(y);
    }
};

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    int p;
    cin >> p;
    
    vector<pair<string, string>> pairs(p);
    DSU dsu;
    
    for (int i = 0; i < p; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
        dsu.unite(pairs[i].first, pairs[i].second);
    }
    
    auto tokenize = [](const string& s) -> vector<string> {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (ss >> token) tokens.push_back(token);
        return tokens;
    };
    
    vector<string> t1 = tokenize(s1);
    vector<string> t2 = tokenize(s2);
    
    if (t1.size() != t2.size()) {
        cout << "NO" << endl;
        return 0;
    }
    
    for (int i = 0; i < t1.size(); ++i) {
        if (t1[i] == t2[i]) continue;
        if (dsu.find(t1[i]) == dsu.find(t2[i])) continue;
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    return 0;
}
