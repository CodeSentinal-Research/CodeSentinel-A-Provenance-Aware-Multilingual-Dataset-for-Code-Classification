Here's a simple C++ solution for the given problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pairs(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pairs[i] = make_pair(a, b);
    }

    sort(pairs.begin(), pairs.end());

    int maxChain = 1;
    int currentChain = 1;

    for (int i = 1; i < n; i++) {
        if (pairs[i].first > pairs[i - 1].second) {
            currentChain++;
        } else {
            maxChain = max(maxChain, currentChain);
            currentChain = 1;
        }
    }

    maxChain = max(maxChain, currentChain);

    cout << maxChain;

    return 0;
}

This code first reads the number of pairs from the input. It then reads the pairs and stores them in a vector. The vector is sorted based on the first element of each pair.

The code then iterates over the sorted pairs. If the second element of the current pair (b) is greater than the first element of the pair before it (a), a new chain is formed. The current chain is incremented. If not, the maximum chain length is updated if the current chain is longer. After iterating over all pairs, the maximum chain length is updated if the current chain is longer.

Finally, the maximum chain length is printed to the output.