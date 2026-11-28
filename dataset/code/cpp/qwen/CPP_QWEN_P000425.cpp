#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; int months; cin >> n >> months;
    vector<int> last_txn(n);
    for(int i=0; i<n; i++) cin >> last_txn[i];
    for(int i=0; i<n; i++) if(last_txn[i] < months) cout << i+1 << " ";
    cout << endl;
    return 0;
}
