#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> titles(n);
    vector<int> years(n);
    for (int i = 0; i < n; i++) cin >> titles[i] >> years[i];
    int q;
    cin >> q;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (years[i] > q) { cout << titles[i] << " " << years[i] << endl; found = true; }
    }
    if (!found) cout << "No Books Found" << endl;
    return 0;
}
