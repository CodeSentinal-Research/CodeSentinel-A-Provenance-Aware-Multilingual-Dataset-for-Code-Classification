#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    
    int p;
    cin >> p;
    
    vector<pair<string, string>> pairs(p);
    for (int i = 0; i < p; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }
    
    // Tokenize sentences
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
    
    // Build similarity map (direct only for P1446, transitive for P1447)
    unordered_map<string, unordered_set<string>> sim;
    for (auto& pr : pairs) {
        sim[pr.first].insert(pr.second);
        sim[pr.second].insert(pr.first);
    }
    
    for (int i = 0; i < t1.size(); ++i) {
        if (t1[i] == t2[i]) continue;
        if (sim[t1[i]].count(t2[i])) continue;
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    return 0;
}
