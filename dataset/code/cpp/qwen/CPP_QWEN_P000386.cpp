#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> accs(n);
    vector<string> details(n);
    for (int i = 0; i < n; i++) cin >> accs[i] >> details[i];
    int q;
    cin >> q;
    while (q--) {
        long long acc;
        cin >> acc;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (accs[i] == acc) { cout << accs[i] << " " << details[i] << endl; found = true; break; }
        }
        if (!found) cout << "Account Not Found" << endl;
    }
    return 0;
}
