#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    vector<int> indegree(26, 0);
    vector<vector<int>> adj(26);
    for (int i = 0; i < N - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];

        int len = min(word1.size(), word2.size());

        for (int j = 0; j < len; j++) {
            if (word1[j] != word2[j]) {
                adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                indegree[word2[j] - 'a']++;
                break;
            }
        }
    }

    string order = "";
    queue<char> q;
    for (int i = 0; i < 26; i++) {
        if (indegree[i] == 0) {
            q.push(char(i + 'a'));
        }
    }

    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        order += curr;

        for (int next : adj[curr - 'a']) {
            indegree[next]--;
            if (indegree[next] == 0) {
                q.push(char(next + 'a'));
            }
        }
    }

    if (order.size() == (size_t)26) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}