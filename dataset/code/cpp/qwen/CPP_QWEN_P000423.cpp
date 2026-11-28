#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int days; cin >> n >> days;
    vector<int> pending_days(n);
    for(int i=0; i<n; i++) cin >> pending_days[i];
    for(int i=0; i<n; i++) if(pending_days[i] > days) cout << i+1 << " ";
    cout << endl;
    return 0;
}
