#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1, closest=a[0];
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(abs(a[mid]-target) < abs(closest-target)) closest = a[mid];
        if(a[mid]<target) l=mid+1; else r=mid-1;
    }
    cout << closest << endl;
    return 0;
}
