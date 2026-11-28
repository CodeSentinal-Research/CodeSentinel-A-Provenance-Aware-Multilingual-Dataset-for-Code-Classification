#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    string startGene, endGene;
    int n;
    cin >> startGene >> endGene >> n;
    vector<string> bank(n);
    for (int i = 0; i < n; i++) cin >> bank[i];
    unordered_set<string> dict(bank.begin(), bank.end());
    if (dict.find(endGene) == dict.end()) {
        cout << -1 << endl;
        return 0;
    }
    queue<string> q;
    q.push(startGene);
    int mutations = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            string gene = q.front(); q.pop();
            if (gene == endGene) {
                cout << mutations << endl;
                return 0;
            }
            for (int j = 0; j < 8; j++) {
                string orig = gene;
                for (char c : {'A','C','G','T'}) {
                    gene[j] = c;
                    if (dict.find(gene) != dict.end()) {
                        q.push(gene);
                        dict.erase(gene);
                    }
                }
                gene = orig;
            }
        }
        mutations++;
    }
    cout << -1 << endl;
    return 0;
}
