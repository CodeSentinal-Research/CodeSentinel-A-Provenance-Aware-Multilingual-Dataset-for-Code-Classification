#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, Coins;
    cin >> N >> Coins;
    
    int* costs = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> costs[i];
    }
    
    sort(costs, costs + N, greater<int>());
    
    int maxBars = 0;
    for(int i = 0; i < N; i++) {
        if(Coins >= costs[i]) {
            Coins -= costs[i];
            maxBars++;
        }
    }
    
    cout << maxBars << endl;
    
    delete[] costs;
    return 0;
}