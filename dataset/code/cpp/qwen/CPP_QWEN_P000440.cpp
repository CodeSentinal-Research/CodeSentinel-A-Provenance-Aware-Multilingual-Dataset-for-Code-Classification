#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1;
    while(l<r) {
        int mid = l+(r-l)/2;
        if(a[mid]>a[r]) l=mid+1; else r=mid;
    }
    cout << a[l] << endl;
    return 0;
}
