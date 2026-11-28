#include <iostream>
#include <vector>
using namespace std;
int main() {
    int target; cin >> target;
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1, idx=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==target) { idx=mid; break; }
        else if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    cout << idx << endl;
    return 0;
}
