#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int missing = 0, idx = 0;
    for(int i=1; ; i++) {
        if(idx<n && a[idx]==i) idx++;
        else { missing++; if(missing==k) { cout << i << endl; return 0; } }
    }
    return 0;
}
