#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    long long l=0, r=0;
    for(int i=0; i<n; i++) { l = max(l, (long long)nums[i]); r += nums[i]; }
    long long ans = r;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, parts=1;
        for(int i=0; i<n; i++) {
            if(sum+nums[i]>mid) { parts++; sum=nums[i]; }
            else sum+=nums[i];
        }
        if(parts<=m) { ans=mid; r=mid-1; } else l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
