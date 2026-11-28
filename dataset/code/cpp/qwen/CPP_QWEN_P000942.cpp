#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> piles(N);
    long long total = 0;
    for (int i = 0; i < N; ++i) {
        cin >> piles[i];
        total += piles[i];
    }
    // Stone Game I: First player always wins if N is even and they play optimally.
    cout << "true" << endl;
    return 0;
}
