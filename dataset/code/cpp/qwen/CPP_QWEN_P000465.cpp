#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, diff; cin >> n >> diff;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int l=0, r=1;
    while(r<n) {
        if(a[r]-a[l]==diff) { cout << "Yes" << endl; return 0; }
        else if(a[r]-a[l]<diff) r++; else l++;
    }
    cout << "No" << endl;
    return 0;
}
