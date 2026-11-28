#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> rolls(n);
    vector<string> names(n);
    for (int i = 0; i < n; i++) cin >> rolls[i] >> names[i];
    int q;
    cin >> q;
    while (q--) {
        int roll;
        cin >> roll;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (rolls[i] == roll) { cout << rolls[i] << " " << names[i] << endl; found = true; break; }
        }
        if (!found) cout << "Record Not Found" << endl;
    }
    return 0;
}
