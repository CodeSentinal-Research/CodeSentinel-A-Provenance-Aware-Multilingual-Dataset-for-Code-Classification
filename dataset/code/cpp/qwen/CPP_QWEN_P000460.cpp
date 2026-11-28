#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1;
    while(l<r) {
        int mid=l+(r-l)/2;
        if(a[mid]>a[mid+1]) r=mid; else l=mid+1;
    }
    int peak = l;
    l=0; r=peak;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==target) { cout << mid << endl; return 0; }
        else if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    l=peak; r=n-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==target) { cout << mid << endl; return 0; }
        else if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    cout << -1 << endl;
    return 0;
}
