#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int idx = -1;
    for(int i=0; i<n; i++) {
        if(a[i]==target) { idx=i; break; }
        if(i>0 && a[i-1]==target) { idx=i-1; break; }
        if(i<n-1 && a[i+1]==target) { idx=i+1; break; }
    }
    cout << idx << endl;
    return 0;
}
