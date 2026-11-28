#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i];
    }
    vector<int> boats(M);
    for (int i = 0; i < M; i++) {
        cin >> boats[i];
    }
    sort(people.begin(), people.end());
    sort(boats.begin(), boats.end());
    int boatsUsed = 0;
    int i = N - 1;
    int j = M - 1;
    while (i >= 0 && j >= 0) {
        if (people[i] <= boats[j]) {
            boatsUsed++;
            i--;
            j--;
        } else {
            i--;
        }
    }
    if (j >= 0) {
        cout << -1 << endl;
    } else {
        cout << boatsUsed << endl;
    }
    return 0;
}