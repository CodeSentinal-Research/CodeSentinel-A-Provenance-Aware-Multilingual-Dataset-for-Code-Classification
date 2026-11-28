#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int m;
    cin >> m;
    map<int, int> lossCount;
    set<int> players;
    
    for (int i = 0; i < m; ++i) {
        int winner, loser;
        cin >> winner >> loser;
        players.insert(winner);
        players.insert(loser);
        lossCount[loser]++;
    }
    
    vector<int> zeroLoss, oneLoss;
    for (int p : players) {
        if (lossCount.find(p) == lossCount.end()) {
            zeroLoss.push_back(p);
        } else if (lossCount[p] == 1) {
            oneLoss.push_back(p);
        }
    }
    
    for (int p : zeroLoss) cout << p << " ";
    cout << endl;
    for (int p : oneLoss) cout << p << " ";
    cout << endl;
    
    return 0;
}
