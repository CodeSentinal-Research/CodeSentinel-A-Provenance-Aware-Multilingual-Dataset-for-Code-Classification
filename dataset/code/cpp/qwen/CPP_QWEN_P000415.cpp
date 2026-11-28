#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string bg; cin >> n >> bg;
    vector<string> bgs(n);
    for(int i=0; i<n; i++) cin >> bgs[i];
    for(int i=0; i<n; i++) if(bgs[i] == bg) cout << i+1 << " ";
    cout << endl;
    return 0;
}
