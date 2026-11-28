#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, c; cin >> n >> c;
    vector<int> stalls(n);
    for(int i=0; i<n; i++) cin >> stalls[i];
    sort(stalls.begin(), stalls.end());
    int l=0, r=stalls[n-1]-stalls[0], ans=0;
    while(l<=r) {
        int mid=l+(r-l)/2;
        int count=1, last=stalls[0];
        for(int i=1; i<n; i++) {
            if(stalls[i]-last>=mid) { count++; last=stalls[i]; }
        }
        if(count>=c) { ans=mid; l=mid+1; } else r=mid-1;
    }
    cout << ans << endl;
    return 0;
}
