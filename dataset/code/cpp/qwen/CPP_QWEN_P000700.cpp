#include <iostream>
#include <vector>
using namespace std;
int findMax(const vector<int>& a, int n) {
    if(n == 1) return a[0];
    return max(a[n - 1], findMax(a, n - 1));
}
int main() {
    int n; cin >> n; vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << findMax(a, n) << endl;
    return 0;
}
