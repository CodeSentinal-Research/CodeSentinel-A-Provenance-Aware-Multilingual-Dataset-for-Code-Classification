#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> depts(n), names(n);
    for (int i = 0; i < n; i++) cin >> depts[i] >> names[i];
    string q;
    cin >> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (depts[i] == q) { cout << depts[i] << " " << names[i] << endl; found = true; }
    }
    if (!found) cout << "No Records Found" << endl;
    return 0;
}
