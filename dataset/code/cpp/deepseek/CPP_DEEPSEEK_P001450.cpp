Here is the code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
    int V;
    cin >> V;
    vector<string> teams(V);
    for (int i = 0; i < V; i++) {
        cin >> teams[i];
    }

    sort(teams.begin(), teams.end(), greater<string>());

    map<char, int> votes;
    for (const auto &team : teams) {
        for (char c : team) {
            votes[c]++;
        }
    }

    sort(teams.begin(), teams.end(), [&](const string &a, const string &b) {
        if (votes[a[0]] != votes[b[0]]) {
            return votes[a[0]] > votes[b[0]];
        }
        return a < b;
    });

    for (const auto &team : teams) {
        cout << team << endl;
    }

    return 0;
}

In this code, we first read the number of teams and the teams themselves. We then sort the teams in descending order of votes. After that, we create a map to store the votes of each team. Finally, we sort the teams again in descending order of votes and alphabetically.