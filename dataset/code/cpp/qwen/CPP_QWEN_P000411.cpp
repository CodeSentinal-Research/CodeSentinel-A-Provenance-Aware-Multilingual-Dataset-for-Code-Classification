#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string keyword; cin >> n >> keyword;
    vector<string> records(n);
    for(int i=0; i<n; i++) cin >> records[i];
    for(int i=0; i<n; i++) if(records[i].find(keyword) != string::npos) cout << i+1 << " ";
    cout << endl;
    return 0;
}
