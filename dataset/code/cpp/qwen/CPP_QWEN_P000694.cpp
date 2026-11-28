#include <iostream>
#include <vector>
using namespace std;
int binSearch(const vector<int>& a, int l, int r, int target) {
    if(l > r) return -1;
    int mid = l + (r - l) / 2;
    if(a[mid] == target) return mid;
    if(a[mid] > target) return binSearch(a, l, mid - 1, target);
    return binSearch(a, mid + 1, r, target);
}
int main() {
    int n, target; cin >> n >> target; vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    cout << binSearch(a, 0, n - 1, target) << endl;
    return 0;
}
