#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> mobiles(n), names(n);
    for (int i = 0; i < n; i++) cin >> mobiles[i] >> names[i];
    int q;
    cin >> q;
    while (q--) {
        string mobile;
        cin >> mobile;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (mobiles[i] == mobile) { cout << mobiles[i] << " " << names[i] << endl; found = true; break; }
        }
        if (!found) cout << "Customer Not Found" << endl;
    }
    return 0;
}
