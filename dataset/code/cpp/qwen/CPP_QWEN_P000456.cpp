#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, h; cin >> n >> h;
    vector<int> piles(n);
    for(int i=0; i<n; i++) cin >> piles[i];
    long long l=1, r=1e9, ans=1e9;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long hours=0;
        for(int i=0; i<n; i++) hours += (piles[i]+mid-1)/mid;
        if(hours<=h) { ans=mid; r=mid-1; } else l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
