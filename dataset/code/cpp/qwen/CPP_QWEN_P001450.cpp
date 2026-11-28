#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int v;
    cin >> v;
    vector<string> votes(v);
    for (int i = 0; i < v; ++i) cin >> votes[i];
    
    if (votes.empty()) return 0;
    string teams = votes[0];
    
    // Count ranks for each position
    int n = teams.length();
    vector<unordered_map<char, int>> posCount(n);
    
    for (const string& vote : votes) {
        for (int i = 0; i < n; ++i) {
            posCount[i][vote[i]]++;
        }
    }
    
    // Sort teams based on criteria
    sort(teams.begin(), teams.end(), [&](char a, char b) {
        for (int i = 0; i < n; ++i) {
            if (posCount[i][a] != posCount[i][b]) 
                return posCount[i][a] > posCount[i][b];
        }
        return a < b;
    });
    
    cout << teams << endl;
    return 0;
}
