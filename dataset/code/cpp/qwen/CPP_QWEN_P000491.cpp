#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int m; cin >> m;
    vector<int> target(m);
    for(int i=0; i<m; i++) cin >> target[i];
    int n; cin >> n;
    vector<string> ops;
    for(int i=1; i<=n; i++) {
        bool found = false;
        for(int t : target) if(t == i) { found = true; break; }
        ops.push_back("Push");
        if(!found) ops.push_back("Pop");
    }
    for(string op : ops) cout << op << " ";
    cout << endl;
    return 0;
}
