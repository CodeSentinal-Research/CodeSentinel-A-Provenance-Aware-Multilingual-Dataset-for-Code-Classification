#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, threshold; cin >> n >> threshold;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int l=1, r=1000000, ans=1000000;
    while(l<=r) {
        int mid=l+(r-l)/2;
        long long sum=0;
        for(int i=0; i<n; i++) sum += (nums[i]+mid-1)/mid;
        if(sum<=threshold) { ans=mid; r=mid-1; } else l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
