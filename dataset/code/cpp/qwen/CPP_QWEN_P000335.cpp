#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int m;
    cin >> m;
    vector<string> queries(m);
    for (int i = 0; i < m; i++) cin >> queries[i];
    string pattern;
    cin >> pattern;
    for (const string& q : queries) {
        int i = 0, j = 0;
        while (i < q.size() && j < pattern.size()) {
            if (q[i] == pattern[j]) j++;
            else if (isupper(q[i])) break;
            i++;
        }
        cout << (j == pattern.size() && (i == q.size() || !isupper(q[i]))) << endl;
    }
    return 0;
}
