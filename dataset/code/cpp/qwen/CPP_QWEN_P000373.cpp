#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> codes(n);
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> codes[i] >> names[i];
    int q;
    cin >> q;
    while (q--) {
        int code;
        cin >> code;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (codes[i] == code) { cout << codes[i] << " " << names[i] << endl; found = true; break; }
        }
        if (!found) cout << "Product Not Found" << endl;
    }
    return 0;
}
