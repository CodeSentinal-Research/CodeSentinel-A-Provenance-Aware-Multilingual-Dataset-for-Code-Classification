#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1005;
int board[MAXN];
int dist[MAXN];

void inputBoard() {
    int N, L, S;
    cin >> N >> L >> S;

    for (int i = 0; i < L; i++) {
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }

    for (int i = 0; i < S; i++) {
        int start, end;
        cin >> start >> end;
        board[start] = -end;
    }
}

int minimumDiceThrows() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    dist[N] = 0;
    q.push(N);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 1; i <= 6; i++) {
            int next = curr + i;

            if (next == N) {
                return dist[curr] + 1;
            }

            if (next <= N && dist[next] > dist[curr] + 1) {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }

            if (board[next] != 0) {
                next = board[next];

                if (dist[next] > dist[curr] + 1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    return -1;
}

int main() {
    inputBoard();
    cout << minimumDiceThrows() << endl;
    return 0;
}