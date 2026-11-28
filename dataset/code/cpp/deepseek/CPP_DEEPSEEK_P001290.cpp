#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    vector<int> piles{A, B, C};
    sort(piles.begin(), piles.end());

    int maxScore = piles[2] - piles[0] + piles[1];

    cout << maxScore << endl;

    return 0;
}