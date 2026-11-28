#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eggDrop(int eggs, int floors) {
    if (floors == 0 || floors == 1) {
        return floors;
    }

    int attempts[eggs+1][floors+1];
    for (int i = 0; i <= eggs; i++) {
        for (int j = 0; j <= floors; j++) {
            attempts[i][j] = j;
        }
    }

    for (int i = 1; i <= eggs; i++) {
        for (int j = 2; j <= floors; j++) {
            attempts[i][j] = min(attempts[i][j-1], attempts[i-1][j-1]) + 1;
            if (attempts[i][j] >= j) {
                attempts[i][j] = j;
            }
        }
    }

    return attempts[eggs][floors];
}

int main() {
    int eggs, floors;
    cout << "Enter number of eggs: ";
    cin >> eggs;
    cout << "Enter number of floors: ";
    cin >> floors;

    int result = eggDrop(eggs, floors);

    cout << "Minimum number of attempts: " << result << endl;

    return 0;
}