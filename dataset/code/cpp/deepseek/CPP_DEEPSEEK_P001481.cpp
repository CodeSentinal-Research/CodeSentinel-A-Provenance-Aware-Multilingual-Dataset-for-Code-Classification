#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, Limit;
    cin >> N >> Limit;
    vector<int> weights(N);
    for(int i=0; i<N; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int i = 0, j = N - 1, boats = 0;
    while(i <= j) {
        if(weights[i] + weights[j] <= Limit) {
            boats++;
            i++;
            j--;
        } else {
            boats++;
            j--;
        }
    }

    cout << boats << "\n";
    return 0;
}