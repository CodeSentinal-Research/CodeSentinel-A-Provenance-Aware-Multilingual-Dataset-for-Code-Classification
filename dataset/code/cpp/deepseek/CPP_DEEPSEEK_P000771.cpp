#include <iostream>
#include <algorithm>

using namespace std;

int optimalBST(int keys[], int freq[], int n) {
    int freqSum = 0;
    for (int i = 0; i < n; i++)
        freqSum += freq[i];

    int freqSumSoFar = 0;
    int cost = 0;

    for (int i = 0; i < n; i++) {
        freqSumSoFar += freq[i];
        cost += abs(freqSumSoFar - (freqSum - freqSumSoFar)) * abs(i - ((n - 1) - (freqSumSoFar - 1)));
    }

    return cost;
}

int main() {
    int keys[] = {1, 2, 3, 4, 5};
    int freq[] = {4, 1, 5, 1, 2};
    int n = sizeof(keys) / sizeof(keys[0]);

    cout << optimalBST(keys, freq, n);

    return 0;
}