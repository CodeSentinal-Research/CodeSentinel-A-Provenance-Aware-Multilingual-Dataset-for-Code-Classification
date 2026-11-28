Here is the C++ code for the given problem.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, AdditionalRocks;
    cin >> N >> AdditionalRocks;

    vector<int> capacities(N);
    vector<int> rocks(N);

    for (int i = 0; i < N; i++) {
        cin >> capacities[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> rocks[i];
    }

    sort(capacities.begin(), capacities.end());
    sort(rocks.begin(), rocks.end());

    int i = 0, j = N - 1;
    int count = 0;

    while (i < N && j >= 0) {
        if (capacities[i] - rocks[j] >= AdditionalRocks) {
            count++;
            i++;
            j--;
        } else {
            j--;
        }
    }

    cout << count << endl;

    return 0;
}

This code reads the capacities and rocks from the input and sorts them. It then iterates over both arrays from both ends. If the difference between the capacity and the rock at the current end of each array is greater than or equal to the additional rocks, it increments the count and moves towards the center of the arrays. Otherwise, it just moves towards the center of the arrays. The maximum number of bags that can be filled is the count of bags that can be filled with the additional rocks.