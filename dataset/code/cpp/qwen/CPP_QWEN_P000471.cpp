#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    vector<int> res(n, 0);
    for(int i=0; i<n; i++) {
        int count = 0;
        for(int j=i+1; j<n; j++) if(a[j]<a[i]) count++;
        res[i] = count;
    }
    for(int i=0; i<n; i++) cout << res[i] << " ";
    cout << endl;
    return 0;
}
