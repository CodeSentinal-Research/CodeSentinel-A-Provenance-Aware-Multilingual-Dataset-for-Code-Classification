#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxConsecutiveOnes = 0;
    int currentConsecutiveOnes = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            currentConsecutiveOnes++;
        } else {
            if (currentConsecutiveOnes > maxConsecutiveOnes) {
                maxConsecutiveOnes = currentConsecutiveOnes;
            }
            currentConsecutiveOnes = 0;
        }
    }

    if (currentConsecutiveOnes > maxConsecutiveOnes) {
        maxConsecutiveOnes = currentConsecutiveOnes;
    }

    cout << maxConsecutiveOnes;

    return 0;
}
This program reads a number `n`, followed by `n` binary integers (either 0 or 1). It then calculates the maximum number of consecutive 1s in the array.