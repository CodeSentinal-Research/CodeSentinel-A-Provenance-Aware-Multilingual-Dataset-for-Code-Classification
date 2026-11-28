#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    
    vector<int> hCuts(r - 1), vCuts(c - 1);
    for (int i = 0; i < r - 1; ++i) cin >> hCuts[i];
    for (int i = 0; i < c - 1; ++i) cin >> vCuts[i];
    
    // Sort in descending order to pick most expensive cuts first
    sort(hCuts.rbegin(), hCuts.rend());
    sort(vCuts.rbegin(), vCuts.rend());
    
    long long cost = 0;
    int hPieces = 1, vPieces = 1;
    int i = 0, j = 0;
    
    while (i < r - 1 && j < c - 1) {
        if (hCuts[i] >= vCuts[j]) {
            cost += (long long)hCuts[i] * vPieces;
            hPieces++;
            i++;
        } else {
            cost += (long long)vCuts[j] * hPieces;
            vPieces++;
            j++;
        }
    }
    
    while (i < r - 1) {
        cost += (long long)hCuts[i] * vPieces;
        i++;
    }
    
    while (j < c - 1) {
        cost += (long long)vCuts[j] * hPieces;
        j++;
    }
    
    cout << cost << endl;
    return 0;
}
