#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> piles(N);
    int xorSum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> piles[i];
        xorSum ^= piles[i];
    }
    cout << (xorSum != 0 ? "First" : "Second") << endl;
    return 0;
}
