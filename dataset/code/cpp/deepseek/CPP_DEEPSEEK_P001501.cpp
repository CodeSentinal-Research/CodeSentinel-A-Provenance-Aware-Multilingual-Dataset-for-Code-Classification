Here is the code:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        cin >> seats[i];
    }

    int maxDistance = 0;
    int distance = 0;

    for (int i = 0; i < n; i++) {
        if (seats[i] == 1) {
            if (i > maxDistance) {
                maxDistance = i;
            }
            distance = max(distance, maxDistance - i);
        }
    }

    cout << distance;

    return 0;
}

This code first reads the number of seats, then the row of seats. It then iterates over the seats, updating the maximum distance and the last seat it found to be occupied. If it finds an occupied seat, it updates the maximum distance if necessary. Finally, it prints the maximum possible distance.