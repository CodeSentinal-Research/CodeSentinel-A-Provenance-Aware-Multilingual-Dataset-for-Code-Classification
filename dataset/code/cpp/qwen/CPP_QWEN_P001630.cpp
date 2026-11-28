#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    long long ops = 0;
    long long diffSum = 0; // Sum of (b[i] - a[i]) so far
    
    for (int i = 0; i < n; ++i) {
        diffSum += b[i] - a[i];
        if (diffSum < 0) {
            ops -= diffSum;
            diffSum = 0;
        }
    }
    
    cout << ops << endl;
    return 0;
}
