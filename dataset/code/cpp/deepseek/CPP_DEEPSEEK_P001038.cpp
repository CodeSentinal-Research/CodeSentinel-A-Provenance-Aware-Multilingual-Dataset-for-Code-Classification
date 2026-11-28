#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int capital[N];
    for (int i = 0; i < N; i++) {
        cin >> capital[i];
    }

    int profit[N];
    for (int i = 0; i < N; i++) {
        cin >> profit[i];
    }

    int initialCapital;
    cin >> initialCapital;

    sort(capital, capital + N, greater<int>());
    sort(profit, profit + N, greater<int>());

    int maxCapital = initialCapital;
    for (int i = 0; i < N; i++) {
        if (i < K && capital[i] > maxCapital) {
            maxCapital = capital[i];
        } else if (i >= K) {
            break;
        }
    }

    cout << maxCapital << endl;

    return 0;
}