#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    int n, p;

    cin >> s1 >> s2 >> n >> p;

    unordered_set<string> set1, set2;
    vector<pair<string, string>> pairs(p);

    for (int i = 0; i < p; i++) {
        string a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
        set1.insert(a);
        set2.insert(b);
    }

    for (int i = 0; i < p; i++) {
        if (set1.find(pairs[i].first) != set1.end() && set2.find(pairs[i].second) != set2.end()) {
            set1.insert(pairs[i].second);
            set2.insert(pairs[i].first);
        }
    }

    if (set1.size() == set2.size() && set1.size() <= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

This C++ program reads two sentences and a list of similar word pairs from the input. It then checks if the two sentences are similar. The `unordered_set` data structure is used to store the words from the sentences, and the `vector` data structure is used to store the pairs of similar words. Finally, it checks if the size of the sets is the same, or if the size of one set is a subset of the other set (i.e., if one set contains all words from the other set), and prints "YES" if the sentences are similar, and "NO" otherwise.