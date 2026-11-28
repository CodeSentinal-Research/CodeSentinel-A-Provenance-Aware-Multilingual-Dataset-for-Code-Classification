#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> regs(n), mans(n);
    for (int i = 0; i < n; i++) cin >> regs[i] >> mans[i];
    string q;
    cin >> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (mans[i] == q) { cout << regs[i] << " " << mans[i] << endl; found = true; }
    }
    if (!found) cout << "No Vehicles Found" << endl;
    return 0;
}
