#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1, floor_val=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(a[mid]<=target) { floor_val=a[mid]; l=mid+1; }
        else r=mid-1;
    }
    cout << floor_val << endl;
    return 0;
}
