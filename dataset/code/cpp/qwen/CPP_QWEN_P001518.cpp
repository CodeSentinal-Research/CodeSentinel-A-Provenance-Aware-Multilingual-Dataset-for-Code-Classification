#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    long long success;
    cin >> n >> m >> success;
    
    vector<int> spells(n), potions(m);
    for (int i = 0; i < n; ++i) cin >> spells[i];
    for (int i = 0; i < m; ++i) cin >> potions[i];
    
    sort(potions.begin(), potions.end());
    
    for (int i = 0; i < n; ++i) {
        long long minPotion = (success + spells[i] - 1) / spells[i]; // Ceiling division
        auto it = lower_bound(potions.begin(), potions.end(), minPotion);
        cout << (potions.end() - it) << " ";
    }
    cout << endl;
    
    return 0;
}
