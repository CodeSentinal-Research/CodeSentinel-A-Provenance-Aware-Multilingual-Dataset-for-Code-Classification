#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n; string dept; cin >> n >> dept;
    vector<string> depts(n); vector<bool> active(n);
    for(int i=0; i<n; i++) { cin >> depts[i] >> active[i]; }
    for(int i=0; i<n; i++) if(depts[i] == dept && active[i]) cout << i+1 << " ";
    cout << endl;
    return 0;
}
