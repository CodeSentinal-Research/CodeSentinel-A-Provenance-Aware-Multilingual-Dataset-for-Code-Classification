Here is the C++ code that will solve the given problem.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool stoneGame(int n, vector<int> &piles) {
    int total = 0;
    for (int pile : piles) {
        total += pile;
    }
    int firstPlayer = total / n;
    int secondPlayer = total - firstPlayer;
    return firstPlayer * 2 > secondPlayer;
}

int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    if (stoneGame(n, piles)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

This code first calculates the total sum of all the piles. Then, it divides the total sum into two piles. The first player will always try to maximize their stones (i.e., try to remove the pile with the largest stone), while the second player will always try to minimize their stones (i.e., try to remove the smallest pile). Finally, it returns whether the first player can win by choosing a pile that maximizes their stones and a pile that minimizes their stones.