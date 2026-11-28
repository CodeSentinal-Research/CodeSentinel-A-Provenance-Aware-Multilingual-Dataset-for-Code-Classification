#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> pages[i];
    long long l=0, r=0;
    for(int i=0; i<n; i++) { l = max(l, (long long)pages[i]); r += pages[i]; }
    long long ans = r;
    while(l<=r) {
        long long mid=l+(r-l)/2;
        long long sum=0, students=1;
        for(int i=0; i<n; i++) {
            if(sum+pages[i]>mid) { students++; sum=pages[i]; }
            else sum+=pages[i];
        }
        if(students<=m) { ans=mid; r=mid-1; } else l=mid+1;
    }
    cout << ans << endl;
    return 0;
}
