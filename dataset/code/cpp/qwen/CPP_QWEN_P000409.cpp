#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string prefix; cin >> n >> prefix;
    vector<string> users(n);
    for(int i=0; i<n; i++) cin >> users[i];
    for(int i=0; i<n; i++) if(users[i].find(prefix) == 0) cout << i+1 << " ";
    cout << endl;
    return 0;
}
