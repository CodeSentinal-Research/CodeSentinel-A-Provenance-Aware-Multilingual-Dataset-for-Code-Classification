#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> people(n), boats(m);
    for (int i = 0; i < n; ++i) cin >> people[i];
    for (int i = 0; i < m; ++i) cin >> boats[i];
    
    sort(people.begin(), people.end());
    sort(boats.begin(), boats.end());
    
    int boatIdx = m - 1;
    int rescued = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        if (boatIdx >= 0 && boats[boatIdx] >= people[i]) {
            rescued++;
            boatIdx--;
        }
    }
    
    if (rescued == n) cout << rescued << endl;
    else cout << -1 << endl;
    
    return 0;
}
