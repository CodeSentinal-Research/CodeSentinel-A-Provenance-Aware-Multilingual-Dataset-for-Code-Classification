#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool stoneGame(int N, vector<int> piles) {
    int total = 0;
    for(int pile : piles) {
        total += pile;
    }

    return total - min(piles[0], piles[N-1]) > min(piles[0], piles[N-1]);
}

int main() {
    int N;
    cin >> N;

    vector<int> piles(N);
    for(int i = 0; i < N; i++) {
        cin >> piles[i];
    }

    if(stoneGame(N, piles)) {
        cout << "true";
    } else {
        cout << "false";
    }

    return 0;
}