#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    int aliceSum = 0;
    int bobSum = 0;

    for (int i = 0; i < N; i++) {
        aliceSum += stones[i];
        if (i % 3 == 0) {
            bobSum += stones[i];
        }
    }

    if (aliceSum > bobSum) {
        cout << "Alice" << endl;
    } else if (aliceSum < bobSum) {
        cout << "Bob" << endl;
    } else {
        cout << "Tie" << endl;
    }

    return 0;
}