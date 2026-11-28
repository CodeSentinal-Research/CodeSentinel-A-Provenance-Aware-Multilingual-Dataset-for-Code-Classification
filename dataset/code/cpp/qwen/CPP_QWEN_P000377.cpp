#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> regs(n), models(n);
    for (int i = 0; i < n; i++) cin >> regs[i] >> models[i];
    int q;
    cin >> q;
    while (q--) {
        string reg;
        cin >> reg;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (regs[i] == reg) { cout << regs[i] << " " << models[i] << endl; found = true; break; }
        }
        if (!found) cout << "Vehicle Not Found" << endl;
    }
    return 0;
}
