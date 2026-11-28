#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, first;
    cin >> n >> first;
    vector<int> encoded(n);
    for (int i = 0; i < n; ++i) cin >> encoded[i];
    
    vector<int> original(n + 1);
    original[0] = first;
    for (int i = 0; i < n; ++i) {
        original[i+1] = original[i] ^ encoded[i];
    }
    
    for (int i = 0; i <= n; ++i) {
        if (i > 0) cout << " ";
        cout << original[i];
    }
    cout << endl;
    return 0;
}
