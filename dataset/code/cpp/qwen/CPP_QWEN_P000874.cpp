#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> encoded(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> encoded[i];
    
    // Total XOR of 1..n
    int totalXor = 0;
    for (int i = 1; i <= n; ++i) totalXor ^= i;
    
    // XOR of encoded[1], encoded[3], ... (every other starting from 1)
    // perm[0] ^ perm[1] = enc[0]
    // perm[1] ^ perm[2] = enc[1]
    // ...
    // XOR of all perm except perm[0] is XOR of enc[1], enc[3]...
    int xorRest = 0;
    for (int i = 1; i < n - 1; i += 2) {
        xorRest ^= encoded[i];
    }
    
    int first = totalXor ^ xorRest;
    
    vector<int> original(n);
    original[0] = first;
    for (int i = 0; i < n - 1; ++i) {
        original[i+1] = original[i] ^ encoded[i];
    }
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << original[i];
    }
    cout << endl;
    return 0;
}
