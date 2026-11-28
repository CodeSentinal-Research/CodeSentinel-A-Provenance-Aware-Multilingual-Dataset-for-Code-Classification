#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> piles(N);
    int xorSum = 0;
    int countOne = 0;
    for (int i = 0; i < N; ++i) {
        cin >> piles[i];
        xorSum ^= piles[i];
        if (piles[i] > 1) countOne++;
    }
    
    // Misere Nim:
    // If all piles are 1: First wins if N is even.
    // Else: First wins if xorSum != 0.
    
    if (countOne == 0) {
        // All 1s
        cout << (N % 2 == 0 ? "First" : "Second") << endl;
    } else {
        cout << (xorSum != 0 ? "First" : "Second") << endl;
    }
    return 0;
}
