#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n-2; i++) {
        int l=i+1, r=n-1;
        while(l<r) {
            int sum = a[i]+a[l]+a[r];
            if(sum==target) { cout << "Yes" << endl; return 0; }
            else if(sum<target) l++; else r--;
        }
    }
    cout << "No" << endl;
    return 0;
}
