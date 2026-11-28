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
        if(a[mid]<a[r]) r=mid; else l=mid+1;
    }
    int max_idx = (l-1+n)%n;
    cout << a[max_idx] << endl;
    return 0;
}
