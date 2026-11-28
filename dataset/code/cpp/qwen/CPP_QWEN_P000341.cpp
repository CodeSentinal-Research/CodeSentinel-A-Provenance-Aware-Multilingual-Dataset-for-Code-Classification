#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, second, target;
    cin >> first >> second >> target;
    int v1 = 0, v2 = 0, vt = 0;
    for (char c : first) v1 = v1 * 10 + (c - 'a');
    for (char c : second) v2 = v2 * 10 + (c - 'a');
    for (char c : target) vt = vt * 10 + (c - 'a');
    cout << (v1 + v2 == vt ? "Yes" : "No") << endl;
    return 0;
}
