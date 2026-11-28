Here is the C++ code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> costs(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> costs[i];
    }

    int totalCost = numeric_limits<int>::max();
    for (int i = 0; i < N; ++i) {
        int cityACost = costs[2 * i];
        int cityBCost = costs[2 * i + 1];

        totalCost = min(totalCost, cityACost + cityBCost);
    }

    cout << totalCost << endl;

    return 0;
}

This program reads the number of people and the costs of sending each person to each city, and then calculates the minimum total cost to send all people to each city. The costs are stored in an array and the costs between people in the same city are compared to find the minimum total cost.