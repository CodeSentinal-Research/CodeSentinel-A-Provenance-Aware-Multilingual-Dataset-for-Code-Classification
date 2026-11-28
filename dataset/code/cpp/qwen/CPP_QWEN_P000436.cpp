#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(a[mid]<target) l=mid+1; else r=mid;
    }
    cout << l << endl;
    return 0;
}
