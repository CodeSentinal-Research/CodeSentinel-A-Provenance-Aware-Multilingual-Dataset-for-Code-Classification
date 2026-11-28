#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, d; cin >> n >> d;
    vector<int> weights(n);
    for(int i=0; i<n; i++) cin >> weights[i];
    long long l=0, r=0;
    for(int i=0; i<n; i++) { l = max(l, (long long)weights[i]); r += weights[i]; }
    long long ans = r;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, days=1;
        for(int i=0; i<n; i++) {
            if(sum+weights[i]>mid) { days++; sum=weights[i]; }
            else sum+=weights[i];
        }
        if(days<=d) { ans=mid; r=mid-1; } else l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
