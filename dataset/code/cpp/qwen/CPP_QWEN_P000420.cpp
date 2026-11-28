#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; cin >> n;
    vector<bool> vacant(n);
    for(int i=0; i<n; i++) cin >> vacant[i];
    for(int i=0; i<n; i++) if(vacant[i]) cout << i+1 << " ";
    cout << endl;
    return 0;
}
