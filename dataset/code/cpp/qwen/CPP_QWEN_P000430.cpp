#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int idx = -1;
    for(int i=n-1; i>=0; i--) if(a[i]==target) { idx=i; break; }
    cout << idx << endl;
    return 0;
}
