Here is the C++ code for the problem:

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> sticks(N);

    for (int i = 0; i < N; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    int minCost = 0;

    for (int i = 1; i < N; i++) {
        minCost += sticks[i - 1];
        sticks[i] += sticks[i - 1];
    }

    cout << minCost << "\n";

    return 0;
}
This code works by first reading the number of sticks, then reading the lengths of the sticks. It sorts the stick lengths to make sure that the shorter sticks are connected before the longer ones. The code then iterates over the sorted stick lengths, adding the sum of the shorter sticks to the minimum cost until it reaches the end of the sorted list. The final minimum cost is printed.