#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> isbns(n), titles(n);
    for (int i = 0; i < n; i++) cin >> isbns[i] >> titles[i];
    int q;
    cin >> q;
    while (q--) {
        string isbn;
        cin >> isbn;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (isbns[i] == isbn) { cout << isbns[i] << " " << titles[i] << endl; found = true; break; }
        }
        if (!found) cout << "Book Not Found" << endl;
    }
    return 0;
}
