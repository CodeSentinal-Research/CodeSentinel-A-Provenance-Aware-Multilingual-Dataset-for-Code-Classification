#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n, k; cin >> m >> n >> k;
    vector<int> a(m), b(n);
    for(int i=0; i<m; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    int l=0, r=m+n;
    while(l<r) {
        int mid = l+(r-l)/2;
        int i = min(mid, m);
        int j = mid - i;
        int a_val = i==0 ? -2e9 : a[i-1];
        int b_val = j==0 ? -2e9 : b[j-1];
        if(max(a_val, b_val) <= (i==m ? 2e9 : a[i]) && max(a_val, b_val) <= (j==n ? 2e9 : b[j])) {
            if(mid >= k) r = mid; else l = mid+1;
        } else l = mid+1;
    }
    // Simplified logic for kth element
    int i=0, j=0, count=0, res=0;
    while(count < k) {
        if(i<m && (j>=n || a[i]<b[j])) res = a[i++]; else res = b[j++];
        count++;
    }
    cout << res << endl;
    return 0;
}
