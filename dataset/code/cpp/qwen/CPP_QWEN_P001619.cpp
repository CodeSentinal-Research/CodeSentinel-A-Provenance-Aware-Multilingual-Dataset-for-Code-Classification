#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> prefixXor(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        prefixXor[i+1] = prefixXor[i] ^ val;
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (prefixXor[r+1] ^ prefixXor[l]) << endl;
    }
    return 0;
}
