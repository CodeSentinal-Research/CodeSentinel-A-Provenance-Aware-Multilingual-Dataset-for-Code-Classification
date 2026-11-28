#include <iostream>
#include <queue>
using namespace std;

int hotPotatoGame(int N, int K) {
    queue<int> players;
    for (int i = 1; i <= N; i++) {
        players.push(i);
    }

    while (players.size() > 1) {
        for (int i = 1; i < K; i++) {
            players.push(players.front());
            players.pop();
        }
        players.pop();
    }

    return players.front();
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << hotPotatoGame(N, K);
    return 0;
}