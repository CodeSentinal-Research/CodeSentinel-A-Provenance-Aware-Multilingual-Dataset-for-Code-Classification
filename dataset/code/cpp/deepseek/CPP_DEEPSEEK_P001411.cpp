Here's the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int matches;
    cin >> matches;

    vector<int> players;
    for (int i = 0; i < matches; i++) {
        int winner, loser;
        cin >> winner >> loser;

        if (find(players.begin(), players.end(), winner) == players.end()) {
            players.push_back(winner);
        }

        if (find(players.begin(), players.end(), loser) == players.end()) {
            players.push_back(loser);
        }
    }

    sort(players.begin(), players.end());

    cout << "Players with zero losses: ";
    for (int player : players) {
        cout << player << " ";
    }
    cout << endl;

    players.clear();

    cout << "Players with exactly one loss: ";
    for (int i = 0; i < matches; i++) {
        int winner, loser;
        cin >> winner >> loser;

        if (winner == loser) {
            continue;
        }

        if (find(players.begin(), players.end(), winner) == players.end()) {
            players.push_back(winner);
        }

        if (find(players.begin(), players.end(), loser) == players.end()) {
            players.push_back(loser);
        }
    }

    sort(players.begin(), players.end());

    cout << "Players with exactly one loss: ";
    for (int player : players) {
        cout << player << " ";
    }
    cout << endl;

    return 0;
}
This code reads the number of matches and for each match, it reads the winner and loser. Then, it checks if the winner or loser is already in the list of players, if not, it adds them to the list. After reading all the matches, it sorts the list of players and prints the players with zero losses followed by the players with exactly one loss.