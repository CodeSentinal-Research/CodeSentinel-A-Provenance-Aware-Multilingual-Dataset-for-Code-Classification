#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=n-1, fp=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(a[mid]==mid) { fp=mid; r=mid-1; }
        else if(a[mid]<mid) l=mid+1; else r=mid-1;
    }
    cout << fp << endl;
    return 0;
}
