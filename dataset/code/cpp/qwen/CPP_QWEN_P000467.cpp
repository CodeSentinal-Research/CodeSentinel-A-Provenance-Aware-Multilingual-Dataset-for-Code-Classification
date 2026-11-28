#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n; cin >> m >> n;
    vector<int> a(m), b(n);
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    if(m > n) { swap(a, b); swap(m, n); }
    int l=0, r=m;
    while(l<=r) {
        int i = l+(r-l)/2;
        int j = (m+n+1)/2 - i;
        int a_left = i==0 ? -2e9 : a[i-1];
        int a_right = i==m ? 2e9 : a[i];
        int b_left = j==0 ? -2e9 : b[j-1];
        int b_right = j==n ? 2e9 : b[j];
        if(a_left <= b_right && b_left <= a_right) {
            if((m+n)%2==0) cout << (max(a_left, b_left) + min(a_right, b_right))/2.0 << endl;
            else cout << max(a_left, b_left) << endl;
            return 0;
        } else if(a_left > b_right) r=i-1; else l=i+1;
    }
    return 0;
}
