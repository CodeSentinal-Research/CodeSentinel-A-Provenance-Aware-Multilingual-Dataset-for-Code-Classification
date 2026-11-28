#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, Success;
    cin >> N >> M >> Success;

    vector<int> Spells(N);
    for (int i = 0; i < N; i++) {
        cin >> Spells[i];
    }

    vector<int> Potions(M);
    for (int i = 0; i < M; i++) {
        cin >> Potions[i];
    }

    sort(Spells.begin(), Spells.end());
    sort(Potions.begin(), Potions.end());

    int spellsIndex = 0, potionsIndex = 0;
    while (spellsIndex < N && potionsIndex < M) {
        if (abs(Spells[spellsIndex] - Potions[potionsIndex]) <= Success) {
            cout << N - spellsIndex << " ";
            spellsIndex++;
        } else if (Spells[spellsIndex] < Potions[potionsIndex]) {
            spellsIndex++;
        } else {
            potionsIndex++;
        }
    }

    return 0;
}