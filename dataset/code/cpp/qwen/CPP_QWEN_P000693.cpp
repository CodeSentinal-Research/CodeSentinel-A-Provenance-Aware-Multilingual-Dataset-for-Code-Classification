#include <iostream>
#include <vector>
using namespace std;
bool linSearch(const vector<int>& a, int n, int target) {
    if(n == 0) return false;
    if(a[n - 1] == target) return true;
    return linSearch(a, n - 1, target);
}
int main() {
    int n, target; cin >> n >> target; vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << (linSearch(a, n, target) ? "true" : "false") << endl;
    return 0;
}
