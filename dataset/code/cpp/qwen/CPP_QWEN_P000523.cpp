#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(vector<int>& head) {
    vector<int> res;
    for (int i = 0; i < head.size(); i++) {
        bool keep = true;
        for (int j = i + 1; j < head.size(); j++) {
            if (head[j] > head[i]) { keep = false; break; }
        }
        if (keep) res.push_back(head[i]);
    }
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> head(n);
    for(int i = 0; i < n; i++) cin >> head[i];
    vector<int> ans = solve(head);
    for(int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
