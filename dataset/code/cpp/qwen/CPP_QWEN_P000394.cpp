#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> brands(n), names(n);
    for (int i = 0; i < n; i++) cin >> brands[i] >> names[i];
    string q;
    cin >> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (brands[i] == q) { cout << brands[i] << " " << names[i] << endl; found = true; }
    }
    if (!found) cout << "No Products Found" << endl;
    return 0;
}
