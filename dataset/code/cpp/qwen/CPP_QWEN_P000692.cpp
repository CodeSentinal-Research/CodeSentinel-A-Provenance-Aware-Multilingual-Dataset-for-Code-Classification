#include <iostream>
#include <vector>
using namespace std;
bool isSorted(const vector<int>& a, int n) {
    if(n <= 1) return true;
    if(a[n - 1] < a[n - 2]) return false;
    return isSorted(a, n - 1);
}
int main() {
    int n; cin >> n; vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << (isSorted(a, n) ? "true" : "false") << endl;
    return 0;
}
