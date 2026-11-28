#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n), phones(n);
    for (int i = 0; i < n; i++) cin >> names[i] >> phones[i];
    int q;
    cin >> q;
    while (q--) {
        string name;
        cin >> name;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (names[i] == name) { cout << names[i] << " " << phones[i] << endl; found = true; break; }
        }
        if (!found) cout << "Contact Not Found" << endl;
    }
    return 0;
}
