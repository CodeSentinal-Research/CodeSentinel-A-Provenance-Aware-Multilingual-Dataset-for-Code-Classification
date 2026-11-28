#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int n, target; cin >> n >> target;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int closest = a[0];
    for(int i=1; i<n; i++) if(abs(a[i]-target) < abs(closest-target)) closest = a[i];
    cout << closest << endl;
    return 0;
}
