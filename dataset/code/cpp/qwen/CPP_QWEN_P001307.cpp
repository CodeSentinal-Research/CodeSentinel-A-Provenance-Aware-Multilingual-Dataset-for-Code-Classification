#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<int> police, thieves;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'P') police.push_back(i);
        else thieves.push_back(i);
    }
    
    int pIdx = 0, tIdx = 0;
    int caught = 0;
    
    while (pIdx < police.size() && tIdx < thieves.size()) {
        if (abs(police[pIdx] - thieves[tIdx]) <= k) {
            caught++;
            pIdx++;
            tIdx++;
        } else if (police[pIdx] < thieves[tIdx]) {
            pIdx++;
        } else {
            tIdx++;
        }
    }
    
    cout << caught << endl;
    return 0;
}
