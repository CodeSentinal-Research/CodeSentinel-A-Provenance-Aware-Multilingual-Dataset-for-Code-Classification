#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    vector<bool> online(n);
    for(int i=0; i<n; i++) cin >> online[i];
    for(int i=0; i<n; i++) if(online[i]) cout << i+1 << " ";
    cout << endl;
    return 0;
}
