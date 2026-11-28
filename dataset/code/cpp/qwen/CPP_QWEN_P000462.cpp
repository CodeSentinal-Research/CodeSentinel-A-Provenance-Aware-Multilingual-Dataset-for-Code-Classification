#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n-1);
    for(int i=0; i<n-1; i++) cin >> a[i];
    int expected = a[0] + (a[n-2]-a[0])/(n-1) * (n-1);
    int actual_sum = 0;
    for(int i=0; i<n-1; i++) actual_sum += a[i];
    cout << expected - (actual_sum - a[0]) << endl;
    return 0;
}
