#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1, first=-1, last=-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(a[mid]==target) { first=mid; r=mid-1; }
        else if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    l=0; r=n-1;
    while(l<=r) {
        int mid = l+(r-l)/2;
        if(a[mid]==target) { last=mid; l=mid+1; }
        else if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    cout << first << " " << last << endl;
    return 0;
}
