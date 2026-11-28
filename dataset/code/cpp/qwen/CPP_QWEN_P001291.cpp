#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> hand(n);
    for (int i = 0; i < n; ++i) cin >> hand[i];
    
    if (n % k != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    map<int, int> freq;
    for (int card : hand) freq[card]++;
    
    for (auto& p : freq) {
        if (p.second > 0) {
            for (int i = 0; i < k; ++i) {
                if (freq[p.first + i] < p.second) {
                    cout << "NO" << endl;
                    return 0;
                }
                freq[p.first + i] -= p.second;
            }
        }
    }
    
    cout << "YES" << endl;
    return 0;
}
